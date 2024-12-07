#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>  // For hex formatting
#include "ALU.h"
#include "Registers.h"
#include "ControlUnit.h"
#include "Memory.h"
#include "InstructionDecoder.h"

using namespace std;

// Function to convert a string to hex
string toHex(const string& instruction) {
    stringstream ss;
    for (size_t i = 0; i < instruction.size(); ++i) {
        ss << hex << setw(2) << setfill('0') << (int)instruction[i];  // Convert each character to hex
    }
    return ss.str();
}

int main() {
    ALU alu;
    Registers registers;
    ControlUnit controlUnit;

    int task = 0;
    cout << "Select Task: \n1. Previous Execution Logic\n2. Fetch-Decode-Execute Cycle\n3. Memory Management\nEnter choice: ";
    cin >> task;

    if (task == 1) {
        vector<string> instructions = {
            "ADD 0 1 2",  // R0 = R1 + R2
            "SUB 1 2 3",  // R1 = R2 - R3
            "NOT 0",      // R0 = ~R0
            "NOP"         // No operation
        };

        for (const string& instruction : instructions) {
            controlUnit.setInstruction(instruction);
            controlUnit.print();

            istringstream inst(instruction);
            string op;
            int r1, r2, r3;
            inst >> op;

            if (op == "ADD" || op == "SUB" || op == "AND" || op == "OR") {
                inst >> r1 >> r2 >> r3;
                int result = alu.execute(op, registers.get(r2), registers.get(r3));
                registers.set(r1, result);
            } else if (op == "NOT") {
                inst >> r1;
                int result = alu.execute(op, registers.get(r1));
                registers.set(r1, result);
            } else if (op == "NOP") {
                // Do nothing
            } else {
                cerr << "Unknown instruction: " << op << endl;
            }

            controlUnit.incrementProgramCounter();
            registers.print();
        }
    } 
    
    else if (task == 2) {
        // New Fetch-Decode-Execute functionality
        Memory memory;

        vector<string> program = {
            "ADD 0 1 2", // R0 = R1 + R2
            "SUB 1 0 3", // R1 = R0 - R3
            "NOT 2",     // R2 = ~R2
            "NOP"        // No operation
        };

        memory.loadInstructions(program);
        cout << "Task 2: Fetch-Decode-Execute with Decoding to Hex\n";

        while (controlUnit.getProgramCounter() < program.size()) {
            string instruction = memory.fetchInstruction(controlUnit.getProgramCounter());
            controlUnit.setInstruction(instruction);

            // Decode instruction to hexadecimal
            string hexInstruction = toHex(instruction);  // Convert instruction to hex
            cout << "Decoded Instruction (Hex): " << hexInstruction << endl;

            // Decode components and execute
            istringstream instStream(instruction);
            string op;
            instStream >> op;

            if (op == "ADD" || op == "SUB" || op == "AND" || op == "OR") {
                int r1, r2, r3;
                instStream >> r1 >> r2 >> r3;
                int result = alu.execute(op, registers.get(r2), registers.get(r3));
                registers.set(r1, result);
            } else if (op == "NOT") {
                int r1;
                instStream >> r1;
                int result = alu.execute(op, registers.get(r1));
                registers.set(r1, result);
            } else if (op == "NOP") {
                // No operation
            } else {
                cerr << "Unknown instruction: " << op << endl;
            }

            controlUnit.incrementProgramCounter();
            registers.print();
        }
    }
    
    else if (task == 3) {
        // Memory Management task
        Memory memory;

        cout << "Testing Memory Management:\n";

        // Writing data to specific memory addresses
        memory.writeData(5, 42);  // Write value 42 to address 5
        memory.writeData(10, 84); // Write value 84 to address 10

        // Reading and printing data from specific memory addresses
        cout << "Read Data [Segment: data, Offset: 5]: " << memory.readData(5) << endl;
        cout << "Read Data [Segment: data, Offset: 10]: " << memory.readData(10) << endl;

        // Print the entire memory content (non-zero values only)
        memory.printMemory();
    }

    else {
        cout << "Invalid task selected." << endl;
    }

    return 0;
}
