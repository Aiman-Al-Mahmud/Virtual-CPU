#### *main.cpp.md*

```markdown
# Main Program Documentation

## Overview
The main program demonstrates the Fetch-Decode-Execute cycle by integrating Memory, Registers, ALU, Control Unit, and Instruction Decoder.

## Workflow

### 1. Load Instructions into Memory
- The program is defined as a set of instructions and loaded into the Memory module.

### 2. Fetch-Decode-Execute Cycle
- *Fetch*: Instructions are fetched from memory based on the Program Counter (PC).
- *Decode*:
  - Instructions are translated into hexadecimal for debugging using the InstructionDecoder.
  - Operation and operands are identified.
- *Execute*:
  - Depending on the operation, the ALU processes the operands.
  - Results are stored in Registers.
  - NOP operations are ignored.

### 3. State Updates
- The Program Counter (PC) is incremented after each instruction.
- Register and memory states are printed after execution.

## Key Functions in main()

### memory.loadInstructions(program)
- *Purpose*: Loads the program instructions into memory.

### memory.fetchInstruction(controlUnit.getProgramCounter())
- *Purpose*: Fetches the instruction at the address pointed to by the PC.

### decodeToHex(instruction)
- *Purpose*: Decodes the current instruction into its hexadecimal equivalent.

### alu.execute(op, registers.get(r2), registers.get(r3))
- *Purpose*: Executes the decoded operation on the operands.

### registers.print()
- *Purpose*: Prints the current state of the registers.

## Example Execution
1. *Instruction 1*: ADD 0 1 2 (R0 = R1 + R2).
   - Decoded: 0x010102.
   - Register updates: R0 gets the sum of R1 and R2.

2. *Instruction 2*: NOT 2 (R2 = ~R2).
   - Decoded: 0x0302.
   - Register updates: R2 gets the bitwise complement of its value.

3. *Final Output*: