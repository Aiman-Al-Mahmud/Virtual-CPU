#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Memory {
private:
    vector<int> data;  // Memory storage for 256 bytes (you can adjust this size as needed)
    vector<string> instructions;  // Store instructions for fetch-decode-execute

public:
    // Constructor to initialize memory with 256 zeros
    Memory() : data(256, 0) {}

    // Write data to a specific address
    void writeData(int address, int value) {
        if (address >= 0 && address < data.size()) {
            data[address] = value; // Write to memory
        } else {
            cerr << "Invalid data address: " << address << endl;
        }
    }

    // Read data from a specific address
    int readData(int address) const {
        if (address >= 0 && address < data.size()) {
            return data[address]; // Return value from memory
        } else {
            cerr << "Invalid data address: " << address << endl;
            return -1; // Invalid read, return error value
        }
    }

    // Print memory content, displaying non-zero values for clarity
    void printMemory() const {
        cout << "Memory Content:\n";
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] != 0) {  // Only print non-zero values
                cout << "[" << i << "]=" << data[i] << " ";
                if (i % 8 == 7) cout << endl; // Break line for every 8 entries
            }
        }
        cout << endl;
    }

    // Load instructions into memory for fetch-decode-execute cycle
    void loadInstructions(const vector<string>& program) {
        instructions = program;
    }

    // Fetch an instruction from memory at the current program counter
    string fetchInstruction(int pc) const {
        if (pc >= 0 && pc < instructions.size()) {
            return instructions[pc];
        } else {
            cerr << "Invalid program counter: " << pc << endl;
            return "";
        }
    }
};

#endif // MEMORY_H
