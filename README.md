# Monty Bytecode Interpreter

This project is a Monty Bytecode interpreter. Monty Bytecode is a specific language that the Monty interpreter reads and executes. This interpreter takes bytecode files as input and executes the opcodes in those files line by line. It is written in C and adheres to the Betty coding style.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [File Structure](#file-structure)
- [Usage](#usage)
- [Opcodes Implemented](#opcodes-implemented)
- [Compilation and Execution](#compilation-and-execution)
- [Examples](#examples)
- [Development](#development)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Monty Bytecode files typically have a `.m` extension. The interpreter reads the Monty bytecode and executes the corresponding stack operations. This project was developed as part of the ALX curriculum to demonstrate an understanding of data structures (stacks, queues), file handling, and algorithm implementation.

## Features

- **Stack and Queue Operations**: Supports basic stack (LIFO) and queue (FIFO) operations.
- **Opcode Processing**: Parses and executes Monty bytecode commands.
- **Error Handling**: Provides meaningful error messages when syntax or runtime errors occur.
- **Modular Code**: Each opcode function is handled by a specific function for better maintainability.

## File Structure

Here is the structure of the project files:

```bash
.monty.c.swp
.monty.h.swp
.opcode_funct3.c.swp
.test.swp
README.md              # Project documentation
a.out                  # Compiled program
monty.c                # Main entry point of the interpreter
monty.h                # Header file containing function prototypes and structure definitions
opcode_funct.c         # Implements opcodes like mod, div, etc.
opcode_funct2.c        # Implements additional opcodes
opcode_funct3.c        # Implements more complex opcodes
split_string.c         # Helper functions for parsing Monty bytecode
test                   # Test cases for the interpreter


## Usage Example

push 1
push 2
push 3
pall
pop
pint

### This bytecode will:

- Push 1, 2, and 3 onto the stack.
- Print all the elements on the stack.
- Pop the top element off the stack.
- Print the top element of the stack.

## Opcodes ImplementedThe following opcodes are supported:

- **push**: Pushes an element to the stack.
- **pall**: Prints all elements in the stack.
- **pint**: Prints the value at the top of the stack.
- **pop**: Removes the top element from the stack.
- **swap**: Swaps the top two elements of the stack.
- **add**: Adds the top two elements of the stack.
- **sub**: Subtracts the top element from the second top element.
- **mul**: Multiplies the top two elements of the stack.
- **div**: Divides the second top element by the top element.
- **mod**: Computes the remainder of the division of the second top element by the top element.
- **rotr**: Rotates the stack to the bottom (last element becomes first).
- **rotl**: Rotates the stack to the top (first element becomes last).


```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
./monty <bytecode_file.m>

