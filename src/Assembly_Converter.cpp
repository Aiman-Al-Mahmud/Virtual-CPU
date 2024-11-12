#include <iostream>
#include <sstream>
#include <unordered_map>
#include <bitset>
#include <vector>

using namespace std;

// Define operation_code table as a hash map
unordered_map<string, string> opcodeTable = {
    {"ADD", "0001"},
    {"SUB", "0010"},
    {"LOAD", "0011"},
    {"STORE", "0100"},
    {"JMP", "0101"},
    {"CMP", "0110"},  //Compare=cmp
    {"AND", "0111"},
    {"OR", "1000"},
    {"NOT", "1001"},
    {"MOV", "1010"},   
    {"NOP", "1011"}   //No operation
};

// Define register mappings
unordered_map<string, string> registerTable = {
    {"R1", "01"},
    {"R2", "10"},
    {"R3", "11"}
};

// Function to convert a single assembly instruction to machine code
string assembleInstruction(const string & instruction) {
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

int main() {
    // Sample instructions
    vector<string> instructions = {
        "ADD R1, R2, R3",
        "STORE R1, 10",
        "LOAD 20"
    };

    // Convert each instruction to machine code and output it
    for (const string& instruction : instructions) {
        string machineCode = assembleInstruction(instruction);
        cout << "Assembly: " << instruction << "\nMachine Code: " << machineCode << endl << endl;
    }

    return 0;
}
