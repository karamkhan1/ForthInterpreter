# Simple Forth Interpreter

This repository contains a simple interpreter for a subset of the Forth programming language, implemented in C.

## Usage

Compile the source files and run the resulting executable. Use the following commands to interact with the interpreter:

- Numbers (e.g., `1`, `2`) push onto the stack.
- Arithmetic operations (e.g., `+`, `-`, `*`, `/`) apply to the top elements of the stack.
- Stack manipulation commands (e.g., `DUP`, `SWAP`) alter the state of the stack.

## Example Run
<img width="1451" alt="Screenshot 2024-02-15 at 9 33 32 PM" src="https://github.com/karamkhan1/ForthInterpreter/assets/79159011/bc98887e-7a27-4f30-ab8d-54efb55390d4">


## Commands

Here is a list of commands supported by the interpreter:

- `+`: Add the top two elements.
- `-`: Subtract the top two elements.
- `*`: Multiply the top two elements.
- `/`: Divide the top two elements.
- `DUP`: Duplicate the top element.
- `.S`: Print the current stack.

For more commands and detailed usage, email me at kkhan6@luc.edu.
