#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip> // For hex formatting
#include <bitset>
#include "ALU.h"
#include "Registers.h"
#include "ControlUnit.h"
#include "Memory.h"
#include "InstructionDecoder.h"
#include "IODevices.h"
#include "IOInstructions.h"

using namespace std;

// Function to convert an integer to binary string
string toBinary(int n, int bits = 8) {
    string result = "";
    for (int i = bits - 1; i >= 0; i--) {
        result += ((n >> i) & 1) ? "1" : "0";
    }
    return result;
}

// Function to convert a string to hex
string toHex(const string& instruction) {
    stringstream ss;
    for (size_t i = 0; i < instruction.size(); ++i) {
        ss << hex << setw(2) << setfill('0') << (int)instruction[i]; // Convert each character to hex
    }
    return ss.str();
}

// Function to convert a string to binary representation
string stringToBinary(const string& input) {
    string binary = "";
    for (char c : input) {
        binary += toBinary(c, 8); // Each character as 8-bit binary
    }
    return binary;
}

// Function to convert binary representation back to string
string binaryToString(const string& binary) {
    string result = "";
    for (size_t i = 0; i < binary.size(); i += 8) {
        result += static_cast<char>(bitset<8>(binary.substr(i, 8)).to_ulong());
    }
    return result;
}

int main() {
    ALU alu;
    ControlUnit controlUnit;
    Memory memory;
    Keyboard keyboard;
    Display display;

    int task = 0;
    cout << "Select Task: \n1. Previous Execution Logic\n2. Fetch-Decode-Execute Cycle\n3. Memory Management\n4. Basic I/O Operations\nEnter choice: ";
    cin >> task;

    if (task == 1) {
        Registers registers(4); // Fixed 4 registers for task 1
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
                string result = alu.execute(op, registers.get(r2), registers.get(r3));
                registers.set(r1, result);
            } else if (op == "NOT") {
                inst >> r1;
                string result = alu.execute(op, registers.get(r1));
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
        Registers registers(4); // Fixed 4 registers for task 2
        // Fetch-Decode-Execute functionality
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
                string result = alu.execute(op, registers.get(r2), registers.get(r3));
                registers.set(r1, result);
            } else if (op == "NOT") {
                int r1;
                instStream >> r1;
                string result = alu.execute(op, registers.get(r1));
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
        cout << "Enter number of registers needed: ";
        int numRegisters;
        cin >> numRegisters;
        Registers registers(numRegisters); // Dynamic registers for task 3
        // Memory Management task
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

    else if (task == 4) { 
        cout << "Enter input for the keyboard (e.g., 1+2 or hello): ";
        string keyboardInput; 
        cin.ignore(); // To ignore the leftover newline character from previous input 
        getline(cin, keyboardInput); 
        keyboard.receiveInput(keyboardInput); 

        Registers registers(keyboardInput.size()); // Dynamically allocate registers based on input size

        vector<string> program = { "IN", "OUT" }; 
        
        for (const string& instruction : program) { 
            controlUnit.setInstruction(instruction); 
            controlUnit.print(); 
            
            if (instruction == "IN") { 
                if (keyboard.isArithmeticExpression(keyboardInput)) { 
                    char op; 
                    int operand1, operand2; 
                    stringstream ss(keyboardInput); 
                    ss >> operand1 >> op >> operand2; 
                    registers.set(1, bitset<8>(operand1).to_string()); // Store operand1 in R1 
                    registers.set(2, bitset<8>(operand2).to_string()); // Store operand2 in R2 

                    // Fix: Use the operation strings from the ALU
                    string operation;
                    if (op == '+') operation = "ADD";
                    else if (op == '-') operation = "SUB";
                    else if (op == '&') operation = "AND";
                    else if (op == '|') operation = "OR";
                    else {
                        cerr << "Unsupported operation: " << op << endl;
                        break;
                    }

                    string result = alu.execute(operation, registers.get(1), registers.get(2));
                    registers.set(0, result); // Store result in R0 
                } else { 
                    string input = keyboard.getInput(); 
                    for (size_t i = 0; i < input.size(); ++i) {
                        registers.set(i, toBinary(input[i])); // Store each character in registers
                    }
                } 
            } else if (instruction == "OUT") { 
                string output = "";
                if (keyboard.isArithmeticExpression(keyboardInput)) { 
                    int result = stoi(registers.get(0), nullptr, 2); // Convert binary result to integer 
                    display.showOutput(to_string(result)); // Display result as decimal
                } else { 
                    for (size_t i = 0; i < keyboardInput.size(); ++i) {
                        output += static_cast<char>(bitset<8>(registers.get(i)).to_ulong()); // Retrieve each character from registers
                    }
                    display.showOutput(output); // Display the input string
                }
            } else { 
                // Handle other instructions (if any)
            } 
            
            controlUnit.incrementProgramCounter(); 
            registers.print(); 
        } 
    } else { 
        cout << "Invalid task selected." << endl;
    }
    return 0;
}
