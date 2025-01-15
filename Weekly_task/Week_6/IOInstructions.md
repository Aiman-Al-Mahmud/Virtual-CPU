# IOInstructions Library

This library provides a simple implementation of I/O instructions, including an `IOInstructions` class that interfaces with `Keyboard`, `Display`, and `Registers` classes to perform input/output operations.

## Classes

### IOInstructions

The `IOInstructions` class is responsible for executing I/O instructions. It interacts with the `Keyboard`, `Display`, and `Registers` classes to receive input, store it in registers, and display output.

#### Constructor

- `IOInstructions(Keyboard &kb, Display &disp, Registers &regs)`: Initializes the `IOInstructions` object with references to `Keyboard`, `Display`, and `Registers` objects.

#### Public Methods

- `void execute(const string &instruction)`: Executes the given instruction. The supported instructions are:
  - `"IN"`: Receives input from the keyboard and stores it in register R0.
  - `"OUT"`: Retrieves output from register R0 and displays it.
  - Unknown instructions are reported as errors.

## Example Usage

```cpp
#include "IOInstructions.h"
#include "Registers.h"
#include "IODevice.h"

int main() {
    Keyboard keyboard;
    Display display;
    Registers registers;
    IOInstructions ioInstructions(keyboard, display, registers);

    keyboard.receiveInput("Hello, World!");
    ioInstructions.execute("IN");
    ioInstructions.execute("OUT");

    return 0;
}
