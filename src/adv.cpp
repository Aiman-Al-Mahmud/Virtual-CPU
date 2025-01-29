#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <bitset>
#include <regex>
#include "ALU.h"
#include "Registers.h"
#include "ControlUnit.h"
#include "Memory.h"
#include "IODevices.h"
#include "IOInstructions.h"
#include "Pipeline.h"
#include "InstructionToBinary.h"
#include "parseInstruction.h"

using namespace std;

int main() {
    ALU alu;
    ControlUnit controlUnit;
    Memory memory;
    Keyboard keyboard;
    Display display;
    Pipeline pipeline;

    cout << "Enter input for the keyboard: (e.g., 3+4, ADD(3,4), R1+R2, ADD(R1,R2))" << endl;
    string input;
    getline(cin, input);
    keyboard.receiveInput(input);

    Registers registers(4);
    vector<string> program = { "IN", "CALL(15)", "ADD(5,7)", "JEQ(10)", "OUT", "CALL(15)", "RET" };

    for (int i = 0; i < program.size(); ++i) {
        string instruction = program[i];
        controlUnit.setInstruction(instruction);
        controlUnit.print();

        pipeline.fetch(controlUnit);

        string operation, operand1, operand2;
        pipeline.decode(controlUnit, operation, operand1, operand2);

        pipeline.execute(operation, operand1, operand2, alu, registers, controlUnit);

        controlUnit.incrementProgramCounter();
        registers.print();

        // Write result to memory
        memory.writeData(controlUnit.getProgramCounter(), stoi(registers.get(0), nullptr, 2));
        memory.printMemory();
    }

    return 0;
}