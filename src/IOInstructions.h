#ifndef IOINSTRUCTIONS_H
#define IOINSTRUCTIONS_H

#include "Registers.h"
#include "IODevices.h"
#include <string>

using namespace std;

class IOInstructions {
private:
    Keyboard & keyboard;
    Display & display;
    Registers & registers;

public:
    IOInstructions(Keyboard & kb, Display & disp, Registers & regs)
        : keyboard(kb), display(disp), registers(regs) {}
                                                            //construtor initialize
    void execute(const string & instruction) {
        if (instruction == "IN") {
            if (keyboard.hasInput()) {
                string input = keyboard.getInput();
                registers.set(0, input); // Store input in R0
            }
        } else if (instruction == "OUT") {
            string output = registers.get(0); // Get output from R0
            display.showOutput(output);
        } else {
            cerr << "Unknown I/O instruction: " << instruction << endl;
        }
    }
};

#endif
