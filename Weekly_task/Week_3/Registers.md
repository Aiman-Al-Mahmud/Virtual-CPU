# Registers Documentation

## Overview
The Registers class represents a simple set of general-purpose registers used to store intermediate results and operands during instruction execution.

## Private Members
- int reg[4]: An array representing four general-purpose registers (R0, R1, R2, R3).

## Functions

### Registers()
- *Description*: Initializes all registers to 0.

### void set(int index, int value)
- *Description*: Sets the value of a register at the specified index.
- *Parameters*:
  - index: The index of the register to set (valid indices are 0-3).
  - value: The value to store in the register.
- *Error Handling*: Displays an error message if an invalid index is provided.

### int get(int index) const
- *Description*: Retrieves the value stored in the specified register.
- *Parameters*:
  - index: The index of the register to retrieve (valid indices are 0-3).
- *Return Value*: The value of the register.
- *Error Handling*: Displays an error message if an invalid index is provided.

### void print() const
- *Description*: Prints the current state of all registers in the format:
