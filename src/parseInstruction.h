#ifndef PARSEINSTRUCTION_H
#define PARSEINSTRUCTION_H

#include <string>
#include <regex>
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

#endif // PARSEINSTRUCTION_H