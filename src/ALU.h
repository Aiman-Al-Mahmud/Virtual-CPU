#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class ALU {
public:
    string execute(const string& operation, const string& operand1, const string& operand2) {
    int op1 = stoi(operand1, nullptr, 2);
    int op2 = stoi(operand2, nullptr, 2);
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
    } else {
        cerr << "Unknown operation: " << operation << endl;
        return "00000000";
    }

    return bitset<8>(result).to_string();
}

};

#endif
