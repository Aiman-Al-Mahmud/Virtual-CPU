#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Memory {
private:
    vector<string> instructions; // Stores the program's instructions
    vector<int> data;            // Stores data for memory addressing
public:
    Memory() : data(256, 0) {}   // Initialize with 256 memory slots (example)

    // Load instructions into memory
    void loadInstructions(const vector<string>& program) {
        instructions = program;
    }

    // Fetch instruction at a specific address
    string fetchInstruction(int address) const {
        if (address >= 0 && address < instructions.size()) {
            return instructions[address];
        } else {
            cerr << "Invalid instruction address: " << address << endl;
            return "NOP";
        }
    }

    // Access memory data
    void writeData(int address, int value) {
        if (address >= 0 && address < data.size()) {
            data[address] = value;
        } else {
            cerr << "Invalid data address: " << address << endl;
        }
    }

    int readData(int address) const {
        if (address >= 0 && address < data.size()) {
            return data[address];
        } else {
            cerr << "Invalid data address: " << address << endl;
            return 0;
        }
    }

    // Print memory data
    void printMemory() const {
        cout << "Memory Data: ";
        for (int i = 0; i < data.size(); ++i) {
            cout << "[" << i << "]=" << data[i] << " ";
            if (i % 8 == 7) cout << endl; // Line break for readability
        }
        cout << endl;
    }
};

#endif
