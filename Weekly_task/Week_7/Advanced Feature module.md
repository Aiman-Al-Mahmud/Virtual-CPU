# Advanced Features Module

This module enhances the virtual CPU emulator by implementing advanced features like subroutines, conditional jumps, and pipeline execution. It integrates multiple components such as the ALU, Registers, Control Unit, Memory, and I/O devices.

## Features Implemented

### 1. **Subroutines and Function Calls**
- Implements `CALL(address)` to jump to a subroutine.
- Uses `RET` to return from the subroutine.

### 2. **Branching and Control Flow**
- Supports conditional jumps like `JEQ(address)` (Jump if equal).
- Implements unconditional jumps such as `JMP(address)`.

### 3. **Pipeline Execution**
- Uses the `Pipeline` class to handle instruction fetching, decoding, and execution separately.
- Enhances performance by organizing execution stages.

### 4. **Instruction to Binary Conversion**
- Uses `InstructionToBinary.h` to convert assembly-like instructions into binary machine code.

## Components Used

### - **ALU (Arithmetic Logic Unit)**
Handles arithmetic and logical operations such as ADD, SUB, MUL, and DIV.

### - **Registers**
Stores data and instruction results.

### - **Control Unit**
Manages program execution flow and maintains program counters.

### - **Memory**
Stores instruction results and execution states.

### - **I/O Devices**
Handles input and output operations for user interaction.

### - **Pipeline**
Implements instruction-level parallelism through fetch, decode, and execute phases.

## Execution Flow
1. The program starts by receiving user input.
2. The `Pipeline` fetches instructions from the `ControlUnit`.
3. Instructions are decoded and executed accordingly.
4. ALU performs calculations and stores results in registers.
5. The results are written into memory and displayed on output devices.

## Example Program Execution
```cpp
vector<string> program = { "IN", "CALL(15)", "ADD(5,7)", "JEQ(10)", "OUT", "CALL(15)", "RET" };
```
- Reads input using `IN`.
- Calls a subroutine at address 15.
- Performs addition (`ADD(5,7)`).
- Jumps conditionally (`JEQ(10)`).
- Displays output (`OUT`).
- Calls and returns from subroutines.

## How to Run
1. Compile and execute the main program.
2. Enter input in the format:
   ```
   3+4
   ADD(3,4)
   R1+R2
   ADD(R1,R2)
   ```
3. The program will execute and display results based on the instructions provided.

## Future Improvements
- Implementing more advanced instruction sets.
- Adding pipeline optimizations.
- Enhancing memory management techniques.

This module significantly improves the virtual CPU emulator by introducing control flow, subroutines, and instruction pipelining. 🚀

