# Pipeline Module

The `Pipeline` module is responsible for handling the instruction pipeline stages in the virtual CPU emulator. It processes instructions by fetching, decoding, and executing them using the `ALU`, `Registers`, and `ControlUnit` components.

## Features
- **Fetch Stage**: Retrieves the instruction from the `ControlUnit`.
- **Decode Stage**: Parses the instruction into an operation and its operands.
- **Execute Stage**: Performs arithmetic, branching, and input/output operations based on the instruction type.

## Dependencies
This module requires the following components:
- `ALU.h`
- `Registers.h`
- `ControlUnit.h`
- `parseInstruction.h`

## Usage
To integrate the `Pipeline` module into your project, include the header file and use the class methods:

```cpp
#include "Pipeline.h"

Pipeline pipeline;
ControlUnit controlUnit;
ALU alu;
Registers registers(4);

// Example usage
string operation, operand1, operand2;
pipeline.fetch(controlUnit);
pipeline.decode(controlUnit, operation, operand1, operand2);
pipeline.execute(operation, operand1, operand2, alu, registers, controlUnit);
```

## Supported Instructions
The `Pipeline` module supports various instruction types, including:
- Arithmetic operations: `ADD`, `SUB`, `MUL`, `DIV`
- Control flow operations: `CALL`, `RET`, `JMP`, `JEQ`, `JNE`
- I/O operations: `IN`, `OUT`

## Error Handling
- Handles invalid arguments with detailed error messages.
- Checks for out-of-range values to prevent memory access issues.

## Future Enhancements
- Improve pipeline efficiency with instruction-level parallelism.
- Implement hazard detection and forwarding mechanisms.
- Optimize register and memory interactions.

---
