# Control Unit Documentation

## Overview
The ControlUnit class orchestrates the execution of instructions by managing the program counter (PC) and the instruction register (IR).

## Private Members
- int programCounter: Stores the current instruction index.
- string instructionRegister: Stores the current instruction being executed.

## Functions

### ControlUnit()
- *Description*: Initializes the program counter to 0 and clears the instruction register.

### void setProgramCounter(int value)
- *Description*: Sets the program counter to a specific value.
- *Parameters*:
- value: The new value for the program counter.

### int getProgramCounter() const
- *Description*: Retrieves the current value of the program counter.
- *Return Value*: The value of the program counter.

### void incrementProgramCounter()
- *Description*: Increments the program counter by 1.

### void setInstruction(const string& instruction)
- *Description*: Updates the instruction register with a new instruction.
- *Parameters*:
- instruction: The instruction to store in the instruction register.

### string getInstruction() const
- *Description*: Retrieves the instruction stored in the instruction register.
- *Return Value*: The stored instruction.

### void print() const
- *Description*: Prints the current values of the program counter and instruction register in the format: