#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <string>
using namespace std;

class ALU {
public:
    int execute(const string & operation, int operand1, int operand2 = 0) {
        if (operation == "ADD") {
            return operand1 + operand2;
        } else if (operation == "SUB") {
            return operand1 - operand2;
        } else if (operation == "AND") {
            return operand1 & operand2;
        } else if (operation == "OR") {
            return operand1 | operand2;
        } else if (operation == "NOT") {
            return ~operand1;
        } else {
            cerr << "Invalid operation: " << operation << endl;
            return 0;
        }
    }
};

#endif 