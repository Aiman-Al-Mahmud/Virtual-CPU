<<<<<<< HEAD
# Main Program Documentation

## Overview
The main.cpp file demonstrates the integration and simulation of a simple processor with an ALU, registers, and control unit. It processes a set of instructions and simulates their execution.

## Key Components
- *ALU*: Performs arithmetic and logical operations.
- *Registers*: Stores intermediate and final results.
- *ControlUnit*: Manages program control flow and instruction tracking.

## Instruction Set
- *ADD r1 r2 r3*: Adds values in registers r2 and r3, stores the result in r1.
- *SUB r1 r2 r3*: Subtracts the value in r3 from r2, stores the result in r1.
- *NOT r1*: Performs a bitwise NOT on the value in r1.
- *NOP*: No operation, simply increments the program counter.

## Workflow
1. *Instruction Parsing*: Instructions are read and parsed from a vector of strings.
2. *Execution*:
 - The ControlUnit loads the instruction into the instruction register.
 - The ALU performs the specified operation.
 - The Registers are updated based on the results.
3. *State Updates*:
 - The program counter is incremented.
 - The current state of the registers is printed.

## Example Output
```shell
PC: 0, IR: ADD 0 1 2
Registers: R0=2 R1=1 R2=1 R3=1 
PC: 1, IR: SUB 1 2 3
Registers: R0=2 R1=0 R2=1 R3=1 
PC: 2, IR: NOT 0
Registers: R0=-3 R1=0 R2=1 R3=1 
PC: 3, IR: NOP
Registers: R0=-3 R1=0 R2=1 R3=1
=======
# Main Program Documentation

## Overview
The main.cpp file demonstrates the integration and simulation of a simple processor with an ALU, registers, and control unit. It processes a set of instructions and simulates their execution.

## Key Components
- *ALU*: Performs arithmetic and logical operations.
- *Registers*: Stores intermediate and final results.
- *ControlUnit*: Manages program control flow and instruction tracking.

## Instruction Set
- *ADD r1 r2 r3*: Adds values in registers r2 and r3, stores the result in r1.
- *SUB r1 r2 r3*: Subtracts the value in r3 from r2, stores the result in r1.
- *NOT r1*: Performs a bitwise NOT on the value in r1.
- *NOP*: No operation, simply increments the program counter.

## Workflow
1. *Instruction Parsing*: Instructions are read and parsed from a vector of strings.
2. *Execution*:
 - The ControlUnit loads the instruction into the instruction register.
 - The ALU performs the specified operation.
 - The Registers are updated based on the results.
3. *State Updates*:
 - The program counter is incremented.
 - The current state of the registers is printed.

## Example Output
```shell
PC: 0, IR: ADD 0 1 2
Registers: R0=2 R1=1 R2=1 R3=1 
PC: 1, IR: SUB 1 2 3
Registers: R0=2 R1=0 R2=1 R3=1 
PC: 2, IR: NOT 0
Registers: R0=-3 R1=0 R2=1 R3=1 
PC: 3, IR: NOP
Registers: R0=-3 R1=0 R2=1 R3=1
>>>>>>> cf41a165e520b19b9232e5ba0d9885091033cdd9
