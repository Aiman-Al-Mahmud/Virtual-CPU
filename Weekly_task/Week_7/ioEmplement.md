# Task 4: Basic I/O Operations

This section provides a detailed implementation of the logic for **Task 4**, which handles basic input and output operations. It interacts with the `Keyboard`, `Display`, and `Registers` classes to perform arithmetic or string processing based on user input.

## Classes and Methods

### Keyboard
- `void receiveInput(const string &input)`: Receives input from the user.
- `bool isArithmeticExpression(const string &input)`: Determines whether the input is an arithmetic expression.
- `string getInput()`: Retrieves the stored input string.

### Display
- `void showOutput(const string &output)`: Displays the given output string.

### Registers
- `Registers(size_t size)`: Dynamically allocates registers based on the given size.
- `void set(size_t index, const string &value)`: Sets the value of a register at the specified index.
- `string get(size_t index)`: Retrieves the value of a register at the specified index.
- `void print()`: Prints the current state of the registers.

### ALU
- `string execute(const string &operation, const string &operand1, const string &operand2)`: Executes arithmetic or logical operations and returns the result.

### ControlUnit
- `void setInstruction(const string &instruction)`: Sets the current instruction for execution.
- `void incrementProgramCounter()`: Increments the program counter.
- `void print()`: Prints the current state of the control unit.


### Output Examples

#### Arithmetic Input
- Input: `1+2`
- Execution:
  ```
  PC: 0, IR: IN
  Registers: R0=00000011 R1=00000001 R2=00000010
  PC: 1, IR: OUT
  Display: 3
  Registers: R0=00000011 R1=00000001 R2=00000010
  ```

#### String Input
- Input: `hello world`
- Execution:
  ```
  PC: 0, IR: IN
  Registers: R0=01101000 R1=01100101 R2=01101100 R3=01101100 R4=01101111 R5=00100000 R6=01110111 R7=01101111 R8=01110010 R9=01101100 R10=01100100
  PC: 1, IR: OUT
  Display: hello world
  Registers: R0=01101000 R1=01100101 R2=01101100 R3=01101100 R4=01101111 R5=00100000 R6=01110111 R7=01101111 R8=01110010 R9=01101100 R10=01100100
  ```
