#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Memory {
private:
    vector<int> data;  // Memory storage for 256 bytes
    vector<string> instructions;  // Store instructions for fetch-decode-execute

public:
    Memory() : data(256, 0) {}

    void writeData(int address, int value) {
        if (address >= 0 && address < data.size()) {
            data[address] = value; // Write to memory
        } else {
            cerr << "Invalid data address: " << address << endl;
        }
    }

    int readData(int address) const {
        if (address >= 0 && address < data.size()) {
            return data[address]; // Return value from memory
        } else {
            cerr << "Invalid data address: " << address << endl;
            return -1;
        }
    }

    void printMemory() const {
        cout << "Memory Content (Hexadecimal):\n";
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] != 0) {  // Only print non-zero values
                cout << "[" << hex << i << "]=" << hex << data[i] << " ";
                if (i % 8 == 7) cout << endl; // Break line for every 8 entries
            }
        }
        cout << endl;
    }

    void loadInstructions(const vector<string>& program) {
        instructions = program;
    }

    string fetchInstruction(int pc) const {
        if (pc >= 0 && pc < instructions.size()) {
            return instructions[pc];
        } else {
            cerr << "Invalid program counter: " << pc << endl;
            return "";
        }
    }
};

#endif
