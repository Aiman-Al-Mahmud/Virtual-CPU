#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <string>
#include <bitset>
#include "ControlUnit.h" // Include ControlUnit header

using namespace std;

class ALU {
public:
    string execute(const string& operation, const string& operand1, const string& operand2) {
        int op1 = stoi(operand1);
        int op2 = stoi(operand2);
        int result = 0;

        if (operation == "ADD") {
            result = op1 + op2;
        } else if (operation == "SUB") {
            result = op1 - op2;
        } else if (operation == "MUL") {
            result = op1 * op2;
        } else if (operation == "DIV") {
            if (op2 == 0) {
                cerr << "Division by zero error.\n";
                return "00000000";
            }
            result = op1 / op2;
        } else if (operation == "AND") {
            result = op1 & op2;
        } else if (operation == "OR") {
            result = op1 | op2;
        } else if (operation == "NOT") {
            result = ~op1;
        }

        return bitset<8>(result).to_string();
    }

    string in(const string& input) {
        // Handle input operations
        return input;
    }

    void out(const string& output) {
        // Handle output operations
        cout << "Output: " << output << endl;
    }

    void call(int address, ControlUnit& controlUnit) {
        controlUnit.callSubroutine(address);
    }

    void ret(ControlUnit& controlUnit) {
        controlUnit.returnFromSubroutine();
    }

    void jmp(int address, ControlUnit& controlUnit) {
        controlUnit.setProgramCounter(address);
    }

    void jeq(int address, ControlUnit& controlUnit) {
        if (controlUnit.getZeroFlag()) {
            controlUnit.setProgramCounter(address);
        }
    }

    void jne(int address, ControlUnit& controlUnit) {
        if (!controlUnit.getZeroFlag()) {
            controlUnit.setProgramCounter(address);
        }
    }
};

#endif // ALU_H
