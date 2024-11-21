#include <iostream>
#include <sstream>
#include <vector>
#include "ALU.h"
#include "Registers.h"
#include "ControlUnit.h"

using namespace std;

int main() {
    // Instantiate components
    ALU alu;
    Registers registers;
    ControlUnit controlUnit;

    // Example instructions
    vector<string> instructions = {
        "ADD 0 1 2",  // R0 = R1 + R2
        "SUB 1 2 3",  // R1 = R2 - R3
        "NOT 0",      // R0 = ~R0
        "NOP"         // No operation
    };

    // Simulate execution
    for (const string & instruction : instructions) {
        controlUnit.setInstruction(instruction);
        controlUnit.print();

        istringstream inst(instruction);
        string op;
        int r1, r2, r3;
        inst >> op;

        if (op == "ADD" || op == "SUB" || op == "AND" || op == "OR") {
            inst >> r1 >> r2 >> r3;
            int result = alu.execute(op, registers.get(r2), registers.get(r3));
            registers.set(r1, result);
        } else if (op == "NOT") {
            inst >> r1;
            int result = alu.execute(op, registers.get(r1));
            registers.set(r1, result);
        } else if (op == "NOP") {
            // Do nothing
        } else {
            cerr<< "Unknown instruction: " << op << endl;
        }

        controlUnit.incrementProgramCounter();
        registers.print();
    }

    return 0;
}
