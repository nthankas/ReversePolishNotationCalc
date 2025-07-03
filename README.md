# ReversePolishNotationCalc

Reverse Polish Notation (RPN) Calculator – C Implementation

Overview:
This project is a command-line Reverse Polish Notation (postfix) calculator implemented in C for the PIC32 microcontroller platform.

It includes:
- A custom stack library for float values
- An RPN parser to evaluate postfix expressions
- A main interactive calculator program
- Thorough unit testing for both libraries

The calculator takes user input in postfix format, handles doubles and arithmetic operators (+ - * /), and returns the calculated result or error messages if the expression is malformed.

---

Features:
- Custom Stack data structure with:
  - Push, Pop, Peek, Size, and Initialization functions
  - Robust error handling (e.g., underflow, overflow, uninitialized use)
- RPN_Evaluate() function using strtok() to tokenize input
  - Supports negative numbers and floating-point values
  - Correct operator ordering (handles division/subtraction properly)
  - Graceful handling of 6+ possible error conditions
- ProcessBackspaces() to sanitize user input with embedded backspace characters
- Interactive main program (Lab04_main.c) with continuous input loop and error feedback
- Test harnesses for both stack.c and rpn.c (stack_test.c, rpn_test.c)

---

File Structure:
- stack.h / stack.c              — Stack library for float values
- stack_test.c                   — Unit tests for stack functions
- rpn.h / rpn.c                  — RPN expression evaluator
- rpn_test.c                     — Unit tests for RPN parsing
- Lab04_main.c                   — Main calculator program
- BOARD.c / BOARD.h              — Microcontroller init code (provided)
- GNUmakefile                    — For Linux compilation
- README.txt                     — This file

---

How to Build and Run (Linux):
To build everything:
    make

To run stack tests:
    make stack_test
    ./stack_test

To run RPN tests:
    make rpn_test
    ./rpn_test

To run the calculator:
    ./Lab4

---

Example Input/Output:

Welcome to the RPN Calculator!

> 5 4 + 6 3 - * 2 /
Result: 7

> 2 +
Error: Not enough operands for operator '+'

> a b +
Error: Invalid token encountered

---

Author:
Nikhil Thankasala
LinkedIn: https://linkedin.com/in/nikhilthankasala
Email: nikhilthankasala@gmail.com
