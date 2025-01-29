#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <iostream>
#include <stack>
#include <string> // Include string header

class ControlUnit {
private:
    int programCounter;
    bool zeroFlag;
    std::stack<int> subroutineStack;
    std::string currentInstruction; // Added member

public:
    ControlUnit() : programCounter(0), zeroFlag(false) {}

    int getProgramCounter() {
        return programCounter;
    }

    void setProgramCounter(int pc) {
        programCounter = pc;
    }

    bool getZeroFlag() {
        return zeroFlag;
    }

    void setZeroFlag(bool flag) {
        zeroFlag = flag;
    }

    void callSubroutine(int address) {
        subroutineStack.push(programCounter + 1);
        programCounter = address;
    }

    void returnFromSubroutine() {
        if (!subroutineStack.empty()) {
            programCounter = subroutineStack.top();
            subroutineStack.pop();
        }
    }

    void incrementProgramCounter() {
        programCounter++;
    }

    void setInstruction(const std::string& instruction) {
        currentInstruction = instruction;
    }

    std::string getInstruction() const {
        return currentInstruction;
    }

    void print() {
        std::cout << "PC: " << programCounter << ", ZF: " << zeroFlag << std::endl;
    }
};

#endif // CONTROLUNIT_H
