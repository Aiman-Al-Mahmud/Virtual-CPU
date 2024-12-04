#ifndef INSTRUCTIONDECODER_H
#define INSTRUCTIONDECODER_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

string InstructionDecoder;
string decodeToHex(const string &instruction) {
    istringstream stream(instruction);
    string op;
    vector<string> operands;

    // Parse instruction into operation and operands
    stream >> op;
    string operand;
    while (stream >> operand) {
        operands.push_back(operand);
    }

    // Convert instruction to hexadecimal representation
    ostringstream hexStream;
    hexStream << "0x" << hex << uppercase;

    // Encode operation (simplified: map each operation to a unique byte)
    if (op == "ADD") hexStream << "01";
    else if (op == "SUB") hexStream << "02";
    else if (op == "NOT") hexStream << "03";
    else if (op == "NOP") hexStream << "00";
    else hexStream << "FF"; // Unknown operation

    // Encode operands as bytes
    for (const string &op : operands) {
        int value = stoi(op); // Convert operand to integer
        hexStream << setw(2) << setfill('0') << value;
    }


        return hexStream.str();
    }


#endif
