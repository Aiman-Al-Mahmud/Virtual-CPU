# ParseInstruction.h

## Overview
`ParseInstruction.h` is a C++ header file that provides a function to parse mathematical and assembly-like instructions into their components.

## Features
- Supports arithmetic expressions (e.g., `3+4`, `5-2`).
- Parses assembly-like instructions (e.g., `ADD(3,4)`, `SUB(R1,R2)`).
- Uses regular expressions for efficient instruction parsing.

## Usage
Include `ParseInstruction.h` in your C++ project and use the `parseInstruction` function to analyze input expressions.

### Example
```cpp
#include <iostream>
#include "ParseInstruction.h"

int main() {
    string operation, operand1, operand2;
    string input = "ADD(3,4)";
    
    if (parseInstruction(input, operation, operand1, operand2)) {
        std::cout << "Operation: " << operation << ", Operand1: " << operand1 << ", Operand2: " << operand2 << std::endl;
    } else {
        std::cout << "Invalid input format." << std::endl;
    }
    return 0;
}
```

## Function Definition
```cpp
bool parseInstruction(const string& input, string& operation, string& operand1, string& operand2);
```

## Supported Patterns
- **Arithmetic Operations:** `3+4`, `5-2`, `6*3`, `8/4`
- **Assembly-like Instructions:** `ADD(3,4)`, `SUB(5,2)`, `ADD(R1,R2)`, `MUL(R2,R3)`

