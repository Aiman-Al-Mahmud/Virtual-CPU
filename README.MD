# Virtual CPU Emulator

This project is a **Virtual CPU Emulator** implemented in C++. It includes essential CPU components such as an **ALU, Control Unit, Registers, Memory, and a Pipeline system** to fetch, decode, and execute instructions.

## Features
- Supports basic arithmetic and logical operations (ADD, SUB,   MUL, DIV, AND, OR, NOT).
- Implements an instruction pipeline with fetch, decode, and execute stages.
- Includes a memory system and register handling.
- Provides input and output functionality.
- Supports jump and branching instructions (CALL, JMP, JEQ, JNE, RET).

## Installation & Compilation
To compile and run the emulator, execute the following commands in the terminal:

```sh
# Navigate to the source directory
cd Virtual-CPU/src

# Compile the project
 g++ -o virtual_cpu main.cpp -std=c++11

# Run the emulator
./virtual_cpu
```

## Code Breakdown
The project consists of multiple classes representing CPU components:

### 1. ALU (Arithmetic Logic Unit)
Handles arithmetic and logical operations.

**Methods:**
```cpp
string execute(const string &operation, int op1, int op2);
```
- **Parameters:**
  - `operation`: Type of operation (ADD, SUB, MUL, DIV, AND, OR, NOT)
  - `op1, op2`: Operands (integers)
- **Returns:** 8-bit binary string of the result.

### 2. Control Unit
Manages the execution of instructions, maintains the program counter, and handles subroutine calls.

**Key Methods:**
```cpp
int getProgramCounter();
void setProgramCounter(int pc);
void incrementProgramCounter();
void setInstruction(const string& instruction);
string getInstruction() const;
```

- int getProgramCounter(): Returns the current value of the     program counter.

- void setProgramCounter(int pc): Sets the program counter to the specified value.

- bool getZeroFlag(): Returns the status of the zero flag.

- void setZeroFlag(bool flag): Sets the zero flag to the specified value.

- void incrementProgramCounter(): Increments the program counter by one.

- void setInstruction(const string& instruction): Sets the current instruction to the provided value.

- string getInstruction() const: Returns the current instruction as a string.

### 3. Registers
Stores temporary values during computation.

**Key Methods:**
```cpp
string get(int index) const;
void set(int index, int value);
```
- 4 registers (R0-R3).

- Values stored as 8-bit binary.

### 4. Memory
Stores instructions and data.

**Key Methods:**
```cpp
void writeData(int address, int data);
void printMemory();
```
- Supports a memory system with 256 addressable locations and a register file with four 8-bit registers (R0-R3).

### 5. IO Devices
Handles input and output operations.

**Key Methods:**
```cpp
void receiveInput(string& input);
void sendOutput(const string& output);
```
- Receives and sends data to/from CPU.
### 6. Pipeline
Processes instructions in three stages: Fetch, Decode, Execute.

**Key Methods:**
```cpp
void fetch(ControlUnit & controlUnit);
void decode(const string& instruction, string& operation, string& operand1, string& operand2);
void execute(...);
```

## Instruction Execution Flow

1. **Fetch**: Retrieve instruction from user input.
2. **Decode**: Break down the instruction into operation and operands.
3. **Execute**: Process the operation using ALU, Registers, Control Unit, and Memory.


## Flowchart
Below is a visual representation of the Virtual CPU Emulator workflow:

```plaintext
+-----------------------------+
|        Start Program        |
+-----------------------------+
               |
               v
+-----------------------------+
|   Receive User Instruction  |
+-----------------------------+
               |
               v
+-----------------------------+
|      Fetch Instruction      |
+-----------------------------+
               |
               v
+-----------------------------+
|     Decode Instruction      |
+-----------------------------+
              |
              v
+----------------------------+
|    Execute Instruction     |
+----------------------------+
              |
              v
+-----------------------------+
|    Store/Display Output     |
+-----------------------------+
              |
              v
+------------------------------+
| Check for RET Instruction?   |
+------------------------------+
              |
              (Yes) --> End Program
              |
              (No)
               v
+------------------------------+
|  Increment Program Counter   |
+------------------------------+
           |
           v
    Repeat Process
```

## Example Execution

```sh
Enter input: 5+5
R0=00001010 R1=00000101 R2=00000101 R3=00000000 
Memory Content (Hexadecimal):
[1]=a 
Display: Result: 10
PC: 1, ZF: 0
Enter input: ADD(R1+R2)
Invalid instruction format: ADD(R1+R2)
R0=00001010 R1=00000101 R2=00000101 R3=00000000 
Memory Content (Hexadecimal):
[1]=a [2]=a 
Display: Result: 10
PC: 2, ZF: 0
Enter input: R1*R2
R0=00011001 R1=00000101 R2=00000101 R3=00000000 
Memory Content (Hexadecimal):
[1]=a [2]=a [3]=19 
Display: Result: 25
PC: 3, ZF: 0
Enter input: CALL(2)
R0=00011001 R1=00000010 R2=00000101 R3=00000000 
Memory Content (Hexadecimal):
[1]=a [2]=a [3]=19 
Display: Result: 25
PC: 3, ZF: 0
```

```sh
Enter input: 5-5
R0=00000000 R1=00000101 R2=00000101 R3=00000000 
Memory Content (Hexadecimal):

Display: Result: 0
PC: 1, ZF: 1
```


---
**Author:** [AIMAN AL MahmUD]  
**Collaborators:**  
- [Mehnaz Ahmmed]  
- [Al Mamun Seikh]  

**GitHub Repo:** [https://github.com/Aiman-Al-Mahmud/Virtual-CPU.git]

