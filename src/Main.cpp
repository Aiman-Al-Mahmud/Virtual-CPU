#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <bitset>
#include <regex>
#include <stack>

using namespace std;

// ALU Class
class ALU {
public:
    string execute(const string & operation, int op1, int op2) {
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
            result = op1 / op2;  // Ensure integer division
        } else if (operation == "AND") {
            result = op1 & op2;
        } else if (operation == "OR") {
            result = op1 | op2;
        } else if (operation == "NOT") {
            result = ~op1;
        }

        return bitset<8>(result).to_string();
    }
};

// ControlUnit Class
class ControlUnit {
private:
    int programCounter;
    bool zeroFlag;
    stack<int> subroutineStack;
    string currentInstruction;

public:
    ControlUnit() : programCounter(0), zeroFlag(false) {}

    int getProgramCounter() { return programCounter; }
    void setProgramCounter(int pc) { programCounter = pc; }
    bool getZeroFlag() { return zeroFlag; }
    void setZeroFlag(bool flag) { zeroFlag = flag; }
    void incrementProgramCounter() { programCounter++; }
    void setInstruction(const string& instruction) { currentInstruction = instruction; }
    string getInstruction() const { return currentInstruction; }

    void print() {
        cout << "PC: " << programCounter << ", ZF: " << zeroFlag << endl;
    }
};

// Registers Class
class Registers {
private:
    vector<string> registers;

public:
    Registers(int size) : registers(size, "00000000") {}

    string get(int index) const { return registers[index]; }
    void set(int index, int value) { registers[index] = bitset<8>(value).to_string(); }

    void print() {
        for (int i = 0; i < registers.size(); ++i) {
            cout << "R" << i << "=" << registers[i] << " ";
        }
        cout << endl;
    }
};

// Memory Class
class Memory {
private:
    vector<int> memory;

public:
    Memory() : memory(256, 0) {}

    void writeData(int address, int data) { memory[address] = data; }

    void printMemory() {
        cout << "Memory Content (Hexadecimal):" << endl;
        for (int i = 0; i < memory.size(); ++i) {
            if (memory[i] != 0) {
                cout << "[" << i << "]=" << hex << memory[i] << " ";
            }
        }
        cout << endl;
    }
};

// IODevices Class
class IODevices {
public:
    void receiveInput(string& input) {
        cout << "Enter input: ";
        getline(cin, input);
    }

    void sendOutput(const string& output) {
        cout << "Display: Result: " << output << endl;
    }
};

// IOInstructions Class
class IOInstructions {
public:
    void handleIN(IODevices& ioDevices, Registers& registers) {
        string input;
        ioDevices.receiveInput(input);
        registers.set(0, stoi(input));
    }

    void handleOUT(IODevices& ioDevices, Registers& registers) {
        string output = to_string(stoi(registers.get(0), nullptr, 2));
        ioDevices.sendOutput(output);
    }
};

// Pipeline Class
class Pipeline {
public:
    void fetch(ControlUnit & controlUnit) {
        // Fetch is simulated by setting instruction in control unit
    }

    void decode(const string& instruction, string& operation, string& operand1, string& operand2) {
        regex pattern(R"((ADD|SUB|MUL|DIV|AND|OR|NOT|CALL|RET|JMP|JEQ|JNE|IN|OUT)\((\d+),?(\d*)\))");
        smatch match;
        if (regex_match(instruction, match, pattern)) {
            operation = match[1];
            operand1 = match[2];
            operand2 = match[3];
        } else {
            cerr << "Invalid instruction format: " << instruction << endl;
        }
    }

    void execute(const string& operation, const string& operand1, const string& operand2, ALU& alu, Registers& registers, ControlUnit& controlUnit, Memory& memory, IOInstructions& ioInstructions, IODevices& ioDevices) {
        try {
            int val1 = 0, val2 = 0;

            if (operand1[0] == 'R') {
                val1 = stoi(registers.get(stoi(operand1.substr(1))), nullptr, 2);
            } else if (isdigit(operand1[0])) {
                val1 = stoi(operand1);
                registers.set(1, val1);
            }

            if (operand2[0] == 'R') {
                val2 = stoi(registers.get(stoi(operand2.substr(1))), nullptr, 2);
            } else if (!operand2.empty() && isdigit(operand2[0])) {
                val2 = stoi(operand2);
                registers.set(2, val2);
            }

            string aluOperation;
            if (operation == "+" || operation == "ADD") aluOperation = "ADD";
            else if (operation == "-" || operation == "SUB") aluOperation = "SUB";
            else if (operation == "*" || operation == "MUL") aluOperation = "MUL";
            else if (operation == "/" || operation == "DIV") aluOperation = "DIV";

            if (!aluOperation.empty()) {
                string result = alu.execute(aluOperation, val1, val2);
                registers.set(0, stoi(result, nullptr, 2));
                controlUnit.setZeroFlag(result == "00000000");
            } else if (operation == "CALL") {
                controlUnit.setProgramCounter(stoi(operand1));
            } else if (operation == "RET") {
                controlUnit.incrementProgramCounter();
            } else if (operation == "JMP") {
                controlUnit.setProgramCounter(stoi(operand1));
            } else if (operation == "JEQ" && controlUnit.getZeroFlag()) {
                controlUnit.setProgramCounter(stoi(operand1));
            } else if (operation == "JNE" && !controlUnit.getZeroFlag()) {
                controlUnit.setProgramCounter(stoi(operand1));
            } else if (operation == "IN") {
                ioInstructions.handleIN(ioDevices, registers);
            } else if (operation == "OUT") {
                ioInstructions.handleOUT(ioDevices, registers);
            }

            controlUnit.incrementProgramCounter();
            registers.print();
            memory.writeData(controlUnit.getProgramCounter(), stoi(registers.get(0), nullptr, 2));
            memory.printMemory();
            ioDevices.sendOutput(to_string(stoi(registers.get(0), nullptr, 2)));
            controlUnit.print();
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << " in operation " << operation << " with operands " << operand1 << ", " << operand2 << endl;
        }
    }

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
};

int main() {
    ALU alu;
    ControlUnit controlUnit;
    Memory memory;
    Pipeline pipeline;
    IODevices ioDevices;
    IOInstructions ioInstructions;
    Registers registers(4);


    while (true) {
        string input;
        ioDevices.receiveInput(input);

        controlUnit.setInstruction(input);
        pipeline.fetch(controlUnit);

        string operation, operand1, operand2;
        if (!pipeline.parseInstruction(input, operation, operand1, operand2)) {
            pipeline.decode(controlUnit.getInstruction(), operation, operand1, operand2);
        }

         pipeline.execute(operation, operand1, operand2, alu, registers, controlUnit, memory, ioInstructions, ioDevices);

        if (operation == "RET") {
            break;
        }
    }
    return 0;
}