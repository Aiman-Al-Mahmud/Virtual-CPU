# Memory Documentation

## Overview
The Memory module provides storage for program instructions and data. It simulates the memory in a computer system, where instructions and data can be stored, fetched, and modified.

## Functions

### Memory()
- *Purpose*: Initializes memory with 256 slots of data, all set to 0.

### void loadInstructions(const vector<string>& program)
- *Purpose*: Loads a set of instructions into memory.
- *Parameters*:
  - program: A vector of instructions to be stored in memory.

### string fetchInstruction(int address) const
- *Purpose*: Retrieves an instruction from a specified memory address.
- *Parameters*:
  - address: The memory address of the instruction.
- *Error Handling*: Returns "NOP" if the address is invalid.

### void writeData(int address, int value)
- *Purpose*: Writes a value to a specified data address in memory.
- *Parameters*:
  - address: The memory address to write to.
  - value: The value to write.
- *Error Handling*: Outputs an error message if the address is invalid.

### int readData(int address) const
- *Purpose*: Reads the value stored at a specified memory address.
- *Parameters*:
  - address: The memory address to read from.
- *Error Handling*: Outputs an error message if the address is invalid.

### void printMemory() const
- *Purpose*: Prints the contents of the memory data section, with line breaks for better readability.

---