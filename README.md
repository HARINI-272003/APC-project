# Arbitrary Precision Calculator

## Overview
The Arbitrary Precision Calculator is a command-line based calculator designed to
perform arithmetic operations on integers of any size with exact precision.
Unlike normal calculators that rely on fixed-size data types, this project removes
numeric limits entirely.

## Why This Project?
Built-in data types such as int, long, and long long overflow when numbers exceed
their storage capacity. This project demonstrates how large-number arithmetic can
be implemented from scratch using data structures instead of relying on language
or hardware limits.

## Key Features
• Supports extremely large integers  
• No overflow or precision loss  
• No scientific notation (e)  
• Handles positive and negative numbers  
• Command-line based input  
• Exact and fully expanded output  

## Implementation Details
• Numbers are represented using a Linked List  
• Each node stores a single digit  
• Arithmetic is performed digit by digit  
• Explicit handling of carry, borrow, and sign  
• No floating-point arithmetic  
• No built-in big integer libraries used  

## Supported Operations
• Addition (+)  
• Subtraction (-)  
• Multiplication (x)  
• Division (/)  

## Sample Inputs
./a.out 123456789123456789 + 987654321987654321

./a.out 999999999999999999999999 * 888888888888888888888888

./a.out -85236984124578003325412563 x 1548787878447778565315877989

./a.out 1000000000000000000000 - 999999999999999999999

./a.out -99999999999999999999 + -11111111111111111111

./a.out 987654321987654321987654321 / 123456789

## How to Compile and Run
gcc *.c -o a.out
./a.out <number1> <operator> <number2>

## Concepts Used
• Linked Lists  
• Dynamic Memory Allocation  
• Data Structures  
• Manual Arithmetic Algorithms  
• Command-Line Argument Parsing  
• Edge Case Handling  

## What I Learned
• How arbitrary precision arithmetic works internally  
• Why hardware data-type limits exist  
• Designing algorithms independent of data size  
• Writing reliable and precision-critical code  
• Strengthening fundamentals of C programming  

## Future Improvements
• Support for decimal numbers  
• Improved error handling  
• Performance optimizations for very large inputs  
• Modular code organization  

## Author
Harini S
