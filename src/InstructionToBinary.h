// InstructionToBinary.h
#ifndef INSTRUCTION_TO_BINARY_H
#define INSTRUCTION_TO_BINARY_H

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <bitset>
#include <string>

using namespace std;

// Define opcode table as a hash map
static unordered_map<string, string> opcodeTable = {
    {"ADD", "0001"},
    {"SUB", "0010"},
    {"LOAD", "0011"},
    {"STORE", "0100"},
    {"JMP", "0101"},
    {"CMP", "0110"},
    {"AND", "0111"},
    {"OR", "1000"},
    {"NOT", "1001"},
    {"MOV", "1010"},
    {"NOP", "1011"}
};

// Define register mappings
static unordered_map<string, string> registerTable = {
    {"R0", "00"},
    {"R1", "01"},
    {"R2", "10"},
    {"R3", "11"}
};

// Function to convert a single assembly instruction to binary machine code
string assembleInstructionToBinary(const string &instruction) {
    istringstream inst(instruction);
    string op, r1, r2, r3;
    inst >> op >> r1;

    // Convert opcode
    string machineCode = opcodeTable[op];
    
    // Convert operands based on instruction type
    if (op == "ADD" || op == "SUB" || op == "AND" || op == "OR") {
        inst >> r2 >> r3;
        machineCode += " " + registerTable[r1] + " " + registerTable[r2] + " " + registerTable[r3];
    } else if (op == "LOAD" || op == "STORE") {
        int address;
        inst >> address;
        machineCode += " " + registerTable[r1] + " " + bitset<8>(address).to_string();
    } else if (op == "JMP") {
        int address;
        inst >> address;
        machineCode += " " + bitset<8>(address).to_string();
    } else if (op == "CMP" || op == "MOV") {
        inst >> r2;
        machineCode += " " + registerTable[r1] + " " + registerTable[r2];
    } else if (op == "NOT") {
        machineCode += " " + registerTable[r1];
    }

    return machineCode;
}

#endif // INSTRUCTION_TO_BINARY_H
