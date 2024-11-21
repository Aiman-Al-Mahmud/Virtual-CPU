# ALU Documentation
## Overview
The Arithmetic Logic Unit (ALU) is a crucial component of the CPU emulator. It performs arithmetic and logical operations as specified by the control unit. This class encapsulates these operations and provides a single interface for execution.

## ALU Class
### Header Guard
```cpp
#ifndef ALU_H
#define ALU_H
#endif 
```
The header guard prevents multiple inclusions of the `ALU` class definition, ensuring efficient compilation.

### Included Libraries
```cpp
#include <iostream>
#include <string>
```
- **`<iostream>`**: Used for error logging with `cerr`.
- **`<string>`**: Enables the use of `std::string` for specifying operations.

### Public Method: `execute`
```cpp
int execute(const string& operation, int operand1, int operand2 = 0);
```
The `execute` method takes three parameters:
- `operation`: A string specifying the operation to perform (e.g., `"ADD"`, `"SUB"`).
- `operand1`: The first operand for the operation.
- `operand2`: An optional second operand for operations requiring two inputs (default is 0).

#### Supported Operations
- **ADD**: Adds two integers.
  ```cpp
  return operand1 + operand2;
  ```
  Example: `execute("ADD", 5, 3)` returns `8`.

- **SUB**: Subtracts the second integer from the first.
  ```cpp
  return operand1 - operand2;
  ```
  Example: `execute("SUB", 7, 2)` returns `5`.

- **AND**: Performs a bitwise AND operation.
  ```cpp
  return operand1 & operand2;
  ```
  Example: `execute("AND", 6, 3)` returns `2`.

- **OR**: Performs a bitwise OR operation.
  ```cpp
  return operand1 | operand2;
  ```
  Example: `execute("OR", 4, 2)` returns `6`.

- **NOT**: Performs a bitwise NOT operation on a single operand.
  ```cpp
  return ~operand1;
  ```
  Example: `execute("NOT", 5)` returns `-6` (in two's complement representation).

#### Error Handling
```cpp
cerr << "Invalid operation: " << operation << endl;
```
If an unsupported operation is specified, the method logs an error message and returns `0` as a default.

### Why Use the ALU Class?
1. **Encapsulation**: The `ALU` class isolates arithmetic and logical operations, making the CPU emulator modular.
2. **Extensibility**: New operations can be added easily by extending the `if-else` logic.
3. **Reusability**: The `execute` method provides a consistent interface for different types of operations.

## Key Features
- Performs both arithmetic and logical operations.
- Handles invalid operations gracefully.
- Designed to work seamlessly with other CPU emulator components.

## Example Usage
```cpp
#include "ALU.h"

int main() {
    ALU alu;
    cout << "ADD: " << alu.execute("ADD", 10, 20) << endl; // Outputs 30
    cout << "NOT: " << alu.execute("NOT", 5) << endl;       // Outputs -6
    cout << "Invalid: " << alu.execute("XYZ", 1, 2) << endl; // Logs error
    return 0;
}
```
This demonstrates how the `ALU` class can be integrated and tested in a main program.

