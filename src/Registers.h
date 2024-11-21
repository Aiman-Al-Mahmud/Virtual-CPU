#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
using namespace std;

class Registers {
private:
    int reg[4]; // Example: 4 general-purpose registers (R0, R1, R2, R3)
public:
    Registers() {
        for (int i = 0; i < 4; ++i) {
            reg[i] = 1;
        }
    }

    void set(int index, int value) {
        if (index >= 0 && index < 4) {
            reg[index] = value;
        } else {
            cerr << "Invalid register index: " << index << endl;
        }
    }

    int get(int index) const {
        if (index >= 0 && index < 4) {
            return reg[index];
        } else {
            cerr << "Invalid register index: " << index << endl;
            return 0;
        }
    }

    void print() const {
        cout << "Registers: ";
        for (int i = 0; i < 4; ++i) {
            cout << "R" << i << "=" << reg[i] << " ";
        }
        cout << endl;
    }
};

#endif 
