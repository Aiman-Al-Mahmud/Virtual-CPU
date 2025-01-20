#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

class Registers {
private:
    vector<bitset<8>> reg; // Dynamic number of general-purpose registers
public:
    Registers(int size) : reg(size) {
        for (int i = 0; i < size; ++i) {
            reg[i] = 0;
        }
    }

    void set(int index, const string& value) {
        if (index >= 0 && index < reg.size()) {
            reg[index] = bitset<8>(value);
        } else {
            cerr << "Invalid register index: " << index << endl;
        }
    }

    string get(int index) const {
        if (index >= 0 && index < reg.size()) {
            return reg[index].to_string();
        } else {
            cerr << "Invalid register index: " << index << endl;
            return "00000000";
        }
    }

    int getRegistersCount() const {
        return reg.size();
    }

    void print() const {
        cout << "Registers: ";
        for (int i = 0; i < reg.size(); ++i) {
            cout << "R" << i << "=" << reg[i] << " ";
        }
        cout << endl;
    }
};

#endif
