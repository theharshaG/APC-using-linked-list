# Arbitrary Precision Calculator Using Doubly Linked List

## Overview

The Arbitrary Precision Calculator (APC) is a command-line calculator developed in C to perform arithmetic operations on large integers using a doubly linked list.

Unlike normal integer data types, which have fixed storage limits, this project stores each digit in a separate linked-list node, allowing calculations on numbers larger than the range of built-in integer types.

## Features

- Addition of large integers
- Subtraction of large integers
- Multiplication of large integers
- Division of large integers
- Command-line argument handling
- Operand and operator validation
- Dynamic memory allocation
- Doubly linked list implementation

## Technologies Used

- C Programming
- Doubly Linked List
- Dynamic Memory Allocation
- File Organization and Modular Programming
- GCC Compiler
- Linux Command Line

## Project Structure

```text
APC/
├── main.c
├── apc.h
├── apc.c
├── addition.c
├── subs.c
├── multiplication.c
├── compare.c
├── digit_to_list.c
├── division.c
├── Makefile
└── README.md
```

## How It Works

Each digit of an input number is stored in a separate node of a doubly linked list. The calculator processes the linked lists to perform arithmetic operations without converting the entire operands into built-in integer types.

The program accepts two operands and an arithmetic operator through command-line arguments, validates the input, performs the requested operation, and displays the result.

## Compilation

Compile the source files using GCC:

```bash
gcc main.c apc.c addition.c subs.c multiplication.c compare.c digit_to_list.c division.c -o apc
```

If a Makefile is configured, you can compile using:

```bash
make
```

## Usage

```bash
./apc operand1 operator operand2
```

### Examples

**Addition**

```bash
./apc 123456789123456789 + 987654321
```

**Subtraction**

```bash
./apc 1000000000 - 123456789
```

**Multiplication**

```bash
./apc 123456789 '*' 98765
```

**Division**

```bash
./apc 123456789 / 123
```

Note: Quote the multiplication operator (`'*'`) to prevent shell wildcard expansion.

## Concepts Practiced

- Doubly linked list operations
- Pointer manipulation
- Dynamic memory allocation using `malloc()` and `free()`
- Arithmetic algorithms
- Carry and borrow handling
- Comparison of large numbers
- Command-line arguments using `argc` and `argv`
- Modular C programming
- Makefile-based compilation

## Learning Outcomes

This project demonstrates how to implement arithmetic operations on large integers using linked lists, strengthen pointer-handling skills, and organize a multi-file C application.

## Author

Harsha G