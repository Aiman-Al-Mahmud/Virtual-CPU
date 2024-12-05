## main.md - Virtual CPU Emulator Documentation

This document provides an overview of the `main.cpp` program, which implements a simple Virtual CPU Emulator. 

**1. Introduction**

This program simulates a central processing unit (CPU) by executing a set of instructions in memory. It follows the classic Fetch-Decode-Execute cycle found in most processors. 

**2. Functionality**

The emulator integrates several components:

* **Memory:** Stores instructions and data for processing.
* **Registers:** Hold temporary values used during instruction execution.
* **Arithmetic Logic Unit (ALU):** Performs arithmetic and logical operations on data.
* **Control Unit:** Controls the flow of the program by managing the Fetch-Decode-Execute cycle.
* **Instruction Decoder:** Decodes instructions into their operation and operand components.

**3. Program Flow**

The program operates in a continuous loop:

1. **Instruction Loading:**
    * Reads a set of instructions from a source (e.g., hardcoded, file).
    * Loads these instructions into memory for access.

2. **Fetch-Decode-Execute Cycle:**
    * **Fetch:**
        * Retrieves the current instruction from memory based on the Program Counter (PC) register.
        * The PC points to the next instruction to be executed.
    * **Decode:**
        * The Instruction Decoder parses the fetched instruction into:
            * A hexadecimal representation for debugging purposes.
            * Its components (operation and operands).
    * **Execute:**
        * The ALU executes the decoded operation on the specified operands stored in registers.
        * Supported operations include `ADD`, `SUB`, `NOT`, and `NOP` (No Operation).
        * The results are stored back into registers.

3. **State Updates:**
    * After each instruction execution:
        * The Program Counter (PC) is incremented to point to the next instruction.
        * The current state of the registers is printed  for debugging purposes.

4. **Loop Continuance:**
    * The program continues looping through the Fetch-Decode-Execute cycle until all instructions in memory have been processed.

**4. Key Functions**

* **memory.loadInstructions(program):**  
    * Loads a set of instructions (represented as a vector of strings) into memory.

**5. Example Output**

```
Decoded Instruction (Hex): 0x010102
Registers: R0=3 R1=1 R2=2 R3=0

Decoded Instruction (Hex): 0x020103
Registers: R0=3 R1=3 R2=2 R3=0

Decoded Instruction (Hex): 0x0302
Registers: R0=3 R1=3 R2=-3 R3=0

Decoded Instruction (Hex): 0x00
Registers: R0=3 R1=3 R2=-3 R3=0
```

