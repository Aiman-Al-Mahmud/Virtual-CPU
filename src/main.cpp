#include <iostream>
#include <sstream>
#include <vector>
#include "ALU.h"
#include "Registers.h"
#include "ControlUnit.h"
#include "Memory.h"
#include "InstructionDecoder.h"

using namespace std;

int main() {
    ALU alu;
    Registers registers;
    ControlUnit controlUnit;
    
    int task = 0;
    cout << "Select Task: \n1. Previous Execution Logic\n2. Fetch-Decode-Execute Cycle\nEnter choice: ";
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
        string hexInstruction = InstructionDecoder;
        string decodeToHex(instruction);
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
     else {
        cout << "Invalid task selected." << endl;
    }

    return 0;
}
