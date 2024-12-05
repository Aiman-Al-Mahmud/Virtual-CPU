## InstructionDecoder.md - Documentation

This document describes the `InstructionDecoder` component within the Virtual CPU Emulator program.

**1. Functionality**

The `InstructionDecoder` plays a crucial role in processing instructions:

   * **Decodes Instructions:** Translates an assembly instruction into a human-readable hexadecimal format for debugging and visualization.
   * **Parses Components:** Identifies the instruction's operation (e.g., ADD, SUB) and its operands (data values).

**2. Key Function**

### `string decodeToHex(const string &instruction)`

* **Purpose:** Converts an assembly instruction string into its hexadecimal representation.
* **Parameters:**
   * `instruction`: (const string&) Reference to the assembly instruction string to be decoded.
* **Return Value:**
   * `string`: The hexadecimal representation of the instruction.
* **Process:**
   1. **Parsing:**
      * Separates the instruction into its operation and operand components.
   2. **Operation Encoding:**
      * Maps the operation to a unique hexadecimal code:
         - ADD -> 0x01
         - SUB -> 0x02
         - NOT -> 0x03
         - NOP (No Operation) -> 0x00
      * If the operation is unrecognized, assigns 0xFF for error handling.
   3. **Operand Encoding:**
      * Encodes each operand as a hexadecimal byte (implementation details might vary depending on the instruction format).
   4. **Combining Codes:**
      * Combines the operation code and encoded operands into a single hexadecimal string.
* **Example:**
   * **Input Instruction:** `ADD R1 R2`
   * **Output (Hexadecimal):** `0x0112` (Assuming R1 and R2 are encoded as bytes 1 and 2, respectively)

**3. Additional Notes**

* The specific format used for operand encoding depends on the design of the instruction set.
* This documentation provides a general overview. Refer to the source code for the complete implementation details. 
