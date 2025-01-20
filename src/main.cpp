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

using namespace std;

bool parseInstruction(const string& input, string& operation, string& operand1, string& operand2) {
    regex pattern1(R"((\d+)\s*([\+\-\*/])\s*(\d+))");
    regex pattern2(R"((ADD|SUB|MUL|DIV)\((\d+),(\d+)\))");
    regex pattern3(R"((R\d+)\s*([\+\-\*/])\s*(R\d+))");
    regex pattern4(R"((ADD|SUB|MUL|DIV)\((R\d+),(R\d+)\))");
    smatch match;

    if (regex_match(input, match, pattern1)) {
        operation = match[2].str();
        operand1 = match[1].str();
        operand2 = match[3].str();
        return true;
    } else if (regex_match(input, match, pattern2)) {
        operation = match[1].str();
        operand1 = match[2].str();
        operand2 = match[3].str();
        return true;
    } else if (regex_match(input, match, pattern3)) {
        operation = match[2].str();
        operand1 = match[1].str();
        operand2 = match[3].str();
        return true;
    } else if (regex_match(input, match, pattern4)) {
        operation = match[1].str();
        operand1 = match[2].str();
        operand2 = match[3].str();
        return true;
    }
    return false;
}

int main() {
    ALU alu;
    ControlUnit controlUnit;
    Memory memory;
    Keyboard keyboard;
    Display display;

    cout << "Enter input for the keyboard: (e.g., 3+4, ADD(3,4), R1+R2, ADD(R1,R2))" << endl;
    string input;
    getline(cin, input);
    keyboard.receiveInput(input);

    Registers registers(4);
    vector<string> program = { "IN", "OUT" };

    for (const string& instruction : program) {
        controlUnit.setInstruction(instruction);
        controlUnit.print();

        if (instruction == "IN") {
            string input = keyboard.getInput();
            string op, operand1, operand2;

            if (parseInstruction(input, op, operand1, operand2)) {
                cout << "Parsed Operation: " << op << ", Operand1: " << operand1 << ", Operand2: " << operand2 << endl;
                try {
                    if (regex_match(operand1, regex(R"(R\d+)")) && regex_match(operand2, regex(R"(R\d+)"))) {
                        int reg1 = stoi(operand1.substr(1));
                        int reg2 = stoi(operand2.substr(1));
                        cout << "Register Indices: " << reg1 << ", " << reg2 << endl;

                        if (reg1 >= registers.getRegistersCount() || reg2 >= registers.getRegistersCount()) {
                            cerr << "Invalid register index" << endl;
                            return 1;
                        }

                        string result = alu.execute(op, registers.get(reg1), registers.get(reg2));
                        registers.set(0, result);
                        cout << "ALU Result: " << result << endl;
                    } else {
                        int val1 = stoi(operand1);
                        int val2 = stoi(operand2);
                        cout << "Immediate Values: " << val1 << ", " << val2 << endl;

                        registers.set(1, bitset<8>(val1).to_string());
                        registers.set(2, bitset<8>(val2).to_string());

                        if (op == "+") op = "ADD";
                        else if (op == "-") op = "SUB";
                        else if (op == "*") op = "MUL";
                        else if (op == "/") op = "DIV";
                        cout << "Mapped Operation: " << op << endl;

                        string result = alu.execute(op, registers.get(1), registers.get(2));
                        registers.set(0, result);
                        cout << "ALU Result: " << result << endl;
                    }
                } catch (const invalid_argument& e) {
                    cerr << "Invalid argument: " << e.what() << endl;
                    return 1;
                } catch (const out_of_range& e) {
                    cerr << "Out of range: " << e.what() << endl;
                    return 1;
                }
            } else {
                cerr << "Invalid input format." << endl;
                return 1;
            }
        } else if (instruction == "OUT") {
            int result = stoi(registers.get(0), nullptr, 2);
            display.showOutput("Result: " + to_string(result));
            cout << "Output Result: " + to_string(result) << endl;
        }

        controlUnit.incrementProgramCounter();
        registers.print();

        memory.writeData(controlUnit.getProgramCounter(), stoi(registers.get(0), nullptr, 2));
        memory.printMemory();
    }

    return 0;
}
