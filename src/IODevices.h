#ifndef IODEVICES_H
#define IODEVICES_H

#include <iostream>
#include <string>
#include <queue>
#include <regex>

using namespace std;

class Keyboard {
private:
    queue<string> inputBuffer;

public:
    void receiveInput(const string &input) {
        inputBuffer.push(input);
    }

    string getInput() {
        if (!inputBuffer.empty()) {
            string input = inputBuffer.front();
            inputBuffer.pop();
            return input;
        } else {
            return "";
        }
    }

    bool hasInput() const {
        return !inputBuffer.empty();
    }

    bool isArithmeticExpression(const string &input) const {
        regex expr(R"(\d+[+\-*\/]\d+)");
        return regex_match(input, expr);
    }
};

class Display {
public:
    void showOutput(const string &output) const {
        cout << "Display: " << output << endl;
    }
};

#endif
