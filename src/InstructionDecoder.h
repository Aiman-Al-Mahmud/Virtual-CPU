#ifndef INSTRUCTIONDECODER_H
#define INSTRUCTIONDECODER_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Convert instruction to binary machine code
string decodeToBinary(const string &instruction) {
    istringstream stream(instruction);
    string op, operand1, operand2;
    stream >> op >> operand1 >> operand2;

    string binaryCode;

    // Opcode and operands to binary
    if (op == "ADD") binaryCode = "0001";
    else if (op == "SUB") binaryCode = "0010";
    else if (op == "LOAD") binaryCode = "0011";
    else if (op == "STORE") binaryCode = "0100";
    else binaryCode = "1111"; // Default for unrecognized opcodes

    // Encode registers or immediate operands in binary
    binaryCode += operand1 == "R0" ? "0000" : "0001"; // Simplified example

    if (op == "LOAD" || op == "STORE") {
        binaryCode += operand2;
    }

    return binaryCode;
}

#endif
