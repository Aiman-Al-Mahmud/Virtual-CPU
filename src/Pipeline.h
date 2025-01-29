#ifndef PIPELINE_H
#define PIPELINE_H

#include "ALU.h"
#include "Registers.h"
#include "ControlUnit.h"
#include "parseInstruction.h"

class Pipeline {
public:
    void fetch(ControlUnit& controlUnit) {
        // Fetch is done by setting instruction in control unit
    }

    void decode(ControlUnit& controlUnit, string& operation, string& operand1, string& operand2) {
        string instruction = controlUnit.getInstruction();
        parseInstruction(instruction, operation, operand1, operand2);
    }

    void execute(const string& operation, const string& operand1, const string& operand2, ALU& alu, Registers& registers, ControlUnit& controlUnit) {
        try {
            if (operation == "ADD" || operation == "SUB" || operation == "MUL" || operation == "DIV") {
                int val1 = (operand1[0] == 'R') ? stoi(registers.get(stoi(operand1.substr(1))), nullptr, 2) : stoi(operand1);
                int val2 = (operand2[0] == 'R') ? stoi(registers.get(stoi(operand2.substr(1))), nullptr, 2) : stoi(operand2);
                string result = alu.execute(operation, to_string(val1), to_string(val2));
                registers.set(0, result);
                controlUnit.setZeroFlag(result == "00000000");
            } else if (operation == "CALL") {
                alu.call(stoi(operand1), controlUnit);
            } else if (operation == "RET") {
                alu.ret(controlUnit);
            } else if (operation == "JMP") {
                alu.jmp(stoi(operand1), controlUnit);
            } else if (operation == "JEQ") {
                alu.jeq(stoi(operand1), controlUnit);
            } else if (operation == "JNE") {
                alu.jne(stoi(operand1), controlUnit);
            } else if (operation == "IN") {
                string input = alu.in(operand1);
                registers.set(0, bitset<8>(stoi(input)).to_string());
            } else if (operation == "OUT") {
                alu.out(registers.get(0));
            } 
        } catch (const invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << " for operation " << operation << " with operands " << operand1 << ", " << operand2 << endl;
        } catch (const out_of_range& e) {
            cerr << "Out of range: " << e.what() << " for operation " << operation << " with operands " << operand1 << ", " << operand2 << endl;
        }
    }
};

#endif // PIPELINE_H