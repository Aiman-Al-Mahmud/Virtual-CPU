#### *InstructionDecoder.md*

```markdown
# Instruction Decoder Documentation

## Overview
The Instruction Decoder translates instructions into hexadecimal representations for debugging and visualization. It also helps parse and identify operation and operand components.

## Functions

### string decodeToHex(const string &instruction)
- *Purpose*: Converts an assembly instruction into a hexadecimal representation.
- *Parameters*:
  - instruction: The instruction string to be decoded.
- *Return Value*: Hexadecimal representation of the instruction.
- *Process*:
  1. Parses the instruction into operation and operands.
  2. Maps operations to unique hexadecimal codes:
     - ADD -> 0x01
     - SUB -> 0x02
     - NOT -> 0x03
     - NOP -> 0x00
  3. Encodes operands as hexadecimal bytes.
- *Error Handling*: Assigns 0xFF for unknown operations.

---
