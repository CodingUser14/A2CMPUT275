# Working With Memory!

## Description
This repository contains solutions I developed in C as part of my coursework for Assignment 2 CMPUT275. 

## What I learned and applied:
The main focus of this assignment was dynamic memory allocation using the heap. Unlike stack memory, the heap memory requires explicit managment by the programmer. This project reinforced the importance of properly freeing allocated memory to prevent memeory leak!

## Process:
The code was developed and compiled on the university's SSH server using a Linux (Ubuntu) enviornment and the GCC compiler. 

## Tasks:
# Q1: 

Example of command execution:

(Bash)
./hamming 234 182 4

hamming.c computes the Hamming distance between two numbers (argv[1] and argv[2]) interpreted in the base by argv[3]. This program compares each pair of the corresponding digits and increments the counter whenever the digits are not the same. 

# Q2:

Example of command execution:

./sstring < input.arg

sstring handles 4 strings labeled a, b, c, d. This program allows the user to manipulate these strings through various operations, including: 
- Replacing string content
- Appending to exisitng strings
- Concatenating multiple strings

This program supports both quoted and unquoted input and can allow users to ouput the resulting string to the terminal.

# Q3:

This program processes a PPM image file and can perfrom image transformation, including:

- Flipping the image across the vertical axis
- Applying a sepia filter

This program reads the pixels from the PPM file and modifes the RGB value.


# Course Description:
Cmput 275 is a introductory computer science course. A list of the specific topics covered include: 
## The Shell
• Executing commands
• I/O Streams and Redirection
• Pipelines
• File Permissions
• PATH Variable
• Shell Scripts
• Makefiles
## The C Programming Language
• Compilation, and compilation tool chain
• Static typing
• Pointers
• C I/O
• Object Lifetime
• Memory Model and Management
• Structures
• Separate Compilation
## The C++ Programming Language
• C++ I/O
• C++ Memory Management
• References
• Operator overloading
• Classes
– The Big 5
2
– Memory management with objects
– Methods
– Inheritance
• STL Classes
• Exceptions and Exception Safety
• Templates
## Algorithms and Data Structures
• Linked lists
• Dynamic arrays
• Graphs
• Graph searches (depth-first search, breadth-first search, Dijkstras, minimum spanning trees)
• Dynamic programming
• Binary search tree