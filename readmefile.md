## Airaj Hussain
## Overview
This project implements a shell program in C. It allows users to interact with the system by executing commands. This README provides an overview of the project structure, files, and instructions for compiling and running the shell.

## Files Included
1. **myshell.c**: This is the main source containing logic for user interaction, parsing commands, and executing them.
2. **utility.c**: This file implements of utility functions declared in myshell.h. It includes functions like `change_directory(char *path)` which perform specific tasks called from the main program.
3. **myshell.h**: This file is the interface between different parts of the shell application. It contains function declarations, constants, and sometimes type definitions used across multiple source files.
4. **Makefile**: The Makefile automates the compilation and build process of the project. It defines rules for building the executable from the source files.
5. **README.md**: This readme file provides documentation for the project, including installation instructions, usage examples, and other important information.

## Compilation and Running
To compile and run the shell, follow these steps:

1. **Open a Linux terminal** and navigate to the directory containing your shell's source codes and the 'Makefile' file.
2. **Type `make`** and press Enter. This command compiles myshell.c and utility.c into an executable named 'myshell'. Any compilation errors will be displayed in the terminal, which need to be fixed before proceeding.
3. **After successful compilation**, start the shell by typing `./myshell` in the terminal and pressing Enter.

## Description of Operation and Commands 
The shell uses commands `cd`, `clr`, `dir`, `environ`, `echo`, `help`, `pause`, and `quit`. They do specific operations like changing directories, clearing screen, directory contents, displaying strings, and quitting.

## Description of Handling Program Invocation
The shell determines its executable path and sets it as the value of the `shell` environment variable. For all other command-line inputs interpreted as program invocation, the shell forks and executes the programs as its child processes. Before execution, the shell sets the `parent` environment variable, ensuring proper handling of program invocation.

## Description of File-Based Command Execution 

The shell sets its executable path as the shell environment variable. It forks and executes other command-line inputs as child processes, setting the parent environment variable before execution for proper handling.