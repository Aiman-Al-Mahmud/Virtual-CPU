#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class ALU {
public:
    string execute(const string &operation, const string &operand1, const string &operand2 = "00000000") {
        bitset<8> op1(operand1);
        bitset<8> op2(operand2);
        bitset<8> result;

        if (operation == "ADD") {
            result = op1.to_ulong() + op2.to_ulong();
        } else if (operation == "SUB") {
            result = op1.to_ulong() - op2.to_ulong();
        } else if (operation == "AND") {
            result = op1 & op2;
        } else if (operation == "OR") {
            result = op1 | op2;
        } else if (operation == "NOT") {
            result = ~op1;
        } else {
            cerr << "Invalid operation: " << operation << endl;
            return "00000000";
        }
        return result.to_string();
    }
};

#endif
