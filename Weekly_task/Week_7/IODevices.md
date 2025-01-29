# IODevices Library

This library provides a simple implementation of I/O devices, including a `Keyboard` class to simulate keyboard input and a `Display` class to simulate screen output.

## Classes

### Keyboard

The `Keyboard` class is responsible for handling keyboard input. It stores the input in a buffer and provides methods to receive and retrieve input. Additionally, it can check if an input is an arithmetic expression.

#### Public Methods

- `void receiveInput(const string &input)`: Receives input and stores it in the input buffer.
- `string getInput()`: Retrieves input from the input buffer. If the buffer is empty, it returns an empty string.
- `bool hasInput() const`: Checks if there is any input in the buffer.
- `bool isArithmeticExpression(const string &input) const`: Checks if the provided input is an arithmetic expression.

### Display

The `Display` class is responsible for displaying output. It provides a simple method to print output to the console.

#### Public Methods

- `void showOutput(const string &output) const`: Displays the provided output.

## Example Usage

```cpp
#include "IODevice.h"

int main() {
    Keyboard keyboard;
    Display display;

    keyboard.receiveInput("42+58");
    if (keyboard.hasInput()) {
        string input = keyboard.getInput();
        if (keyboard.isArithmeticExpression(input)) {
            display.showOutput("Arithmetic expression received: " + input);
        } else {
            display.showOutput("Non-arithmetic input received: " + input);
        }
    }

    return 0;
}
