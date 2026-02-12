# APC-in-C

# Overview
- APC (Arbitrary Precision Calculator) is a console-based C program for performing arithmetic on integers of **any size**.
- Uses **linked lists** to represent numbers digit by digit.
- Demonstrates **data structures, pointers, dynamic memory allocation, and modular programming** in C.
- Allows high-precision calculations beyond standard C data type limits.

# Features
- Perform arithmetic on integers of unlimited length.
- Core operations: 
  - Addition (+) 
  - Subtraction (-) 
  - Multiplication (×) 
  - Division (÷)
- Linked list based number representation.
- Efficient **carry and borrow** handling.
- Modular and readable C implementation.
- Lightweight, implemented entirely in C.

# How to Run
- Clone the repository:
  - `git clone https://github.com/gayathrikarasi-dev/APC.git`
  - `cd apc-in-c`
- Compile the program:
  - `gcc *.c -o apc`
- Run the program:
  - `./apc`

# Usage Examples
- Addition:
  - `./apc 1234567456789 + 9876543654321`
- Subtraction:
  - `./apc 9321987654321 - 1289123456789`
- Multiplication:
  - `./apc 123456789 * 987654321`
- Division:
  - `./apc 987654321987654321 / 123456789`

# Notes
- Numbers are stored as **linked lists**, one digit per node.
- Program avoids built-in numeric types like `int`, `long`, `long long`.
- Designed for **learning purposes**:
  - Memory management
  - Pointer manipulation
  - Arithmetic algorithm design
  - Modular C programming

# Skills Learned
- C programming
- Implementing **linked lists**
- Dynamic memory allocation (`malloc`, `free`)
- Pointer handling and memory management
- Algorithm design for large-number arithmetic
- Modular project structure
- Debugging complex C programs

# Project Structure

apc-in-c/
├─ images/
│  ├─ Addition.png
│  ├─ Subtraction.png
│  ├─ Multiplication.png
│  ├─ Division.png
│  └─ Errors.png
├─ include/
│  └─ apc.h
├─ src/
│  ├─ add.c
│  ├─ apc.c
│  ├─ div.c
│  ├─ main.c
│  ├─ mul.c
│  └─ sub.c
├─ README.md
└─ .gitignore
