# Instruction Formats for Virtual CPU

This document outlines the format and encoding for each supported instruction in the virtual CPU's instruction set.

## General Instruction Format

Each instruction consists of:
- **Opcode**: Specifies the operation (e.g., ADD, LOAD).
- **Operands**: Specifies registers or memory addresses used by the instruction.

### 1. ADD - Addition
- **Format**: `ADD R1, R2, R3`
- **Description**: Adds the contents of `R2` and `R3` and stores the result in `R1`.
- **Opcode**: `0001`
- **Example**: `ADD R1, R2, R3` translates to `0001 01 10 11`

### 2. SUB - Subtraction
- **Format**: `SUB R1, R2, R3`
- **Description**: Subtracts the contents of `R3` from `R2` and stores the result in `R1`.
- **Opcode**: `0010`
- **Example**: `SUB R1, R2, R3` translates to `0010 01 10 11`

### 3. LOAD - Load from Memory
- **Format**: `LOAD R1, Address`
- **Description**: Loads the value from the specified memory address into `R1`.
- **Opcode**: `0011`
- **Example**: `LOAD R1, 0x0A` translates to `0011 01 00001010`

### 4. STORE - Store to Memory
- **Format**: `STORE R1, Address`
- **Description**: Stores the value in `R1` to the specified memory address.
- **Opcode**: `0100`
- **Example**: `STORE R1, 0x0A` translates to `0100 01 00001010`

### 5. JMP - Jump
- **Format**: `JMP Address`
- **Description**: Sets the program counter to the specified address, enabling conditional or unconditional jumps.
- **Opcode**: `0101`
- **Example**: `JMP 0x0A` translates to `0101 00001010`

### 6. CMP - Compare
- **Format**: `CMP R1, R2`
- **Description**: Compares `R1` and `R2`, setting flags accordingly.
- **Opcode**: `0110`
- **Example**: `CMP R1, R2` translates to `0110 01 10`

### 7. AND - Logical AND
- **Format**: `AND R1, R2, R3`
- **Description**: Performs a bitwise AND on `R2` and `R3` and stores the result in `R1`.
- **Opcode**: `0111`
- **Example**: `AND R1, R2, R3` translates to `0111 01 10 11`

### 8. OR - Logical OR
- **Format**: `OR R1, R2, R3`
- **Description**: Performs a bitwise OR on `R2` and `R3` and stores the result in `R1`.
- **Opcode**: `1000`
- **Example**: `OR R1, R2, R3` translates to `1000 01 10 11`

### 9. NOT - Logical NOT
- **Format**: `NOT R1`
- **Description**: Performs a bitwise NOT on `R1` and stores the result back in `R1`.
- **Opcode**: `1001`
- **Example**: `NOT R1` translates to `1001 01`

### 10. MOV - Move
- **Format**: `MOV R1, R2`
- **Description**: Copies the value from `R2` to `R1`.
- **Opcode**: `1010`
- **Example**: `MOV R1, R2` translates to `1010 01 10`

### 11. NOP - No Operation
- **Format**: `NOP`
- **Description**: Does nothing; used for timing adjustments.
- **Opcode**: `1011`
- **Example**: `NOP` translates to `1011`

---

## Register and Address Encoding

- **Registers**: Represented as 2-bit binary values:
  - `R1`: `01`
  - `R2`: `10`
  - `R3`: `11`

- **Memory Addresses**: Represented in 8-bit binary.

This format provides a clear structure for encoding each instruction for the virtual CPU.
