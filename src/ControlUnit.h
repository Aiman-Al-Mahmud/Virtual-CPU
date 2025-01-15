#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <iostream>
#include <string>
using namespace std;

class ControlUnit {
private:
    int programCounter;
    string instructionRegister;
public:
    ControlUnit() : programCounter(0), instructionRegister("") {}

    void setProgramCounter(int value) {
        programCounter = value;
    }

    int getProgramCounter() const {
        return programCounter;
    }

    void incrementProgramCounter() {
        programCounter++;
    }

    void setInstruction(const string & instruction) {
        instructionRegister = instruction;
    }

    string getInstruction() const {
        return instructionRegister;
    }

    void print() const {
        cout << "PC: " << programCounter << ", IR: " << instructionRegister << endl;
    }
};

#endif
