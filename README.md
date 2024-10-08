# Get Next Line - C Project

## Overview

This project involves implementing a function called `get_next_line` in C, which reads a line from a file descriptor. It focuses on using static variables and dynamic memory allocation to achieve efficient file reading.

## Table of Contents

- [Overview](#overview)
- [Goals](#goals)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)
- [How to Use](#how-to-use)
- [Compilation](#compilation)
- [Testing](#testing)


## Goals

The primary goal of this project is to implement a convenient function that reads one line at a time from a file descriptor and returns it. Through this project, you will gain a deeper understanding of:

- Static variables in C
- Efficient memory management
- Proper file handling

## Mandatory Part

- **Function Name**: `get_next_line`

- **Prototype**:
  ```c
  char *get_next_line(int fd);
  Get Next Line - C Project
Overview

This project involves implementing a function called get_next_line in C, which reads a line from a file descriptor. It focuses on using static variables and dynamic memory allocation to achieve efficient file reading.
Table of Contents

    Project Overview
    Goals
    Mandatory Part
    Bonus Part
    How to Use
    Compilation
    Testing
    License

Goals

The primary goal of this project is to implement a convenient function that reads one line at a time from a file descriptor and returns it. Through this project, you will gain a deeper understanding of:

    Static variables in C.
    Efficient memory management.
    Proper file handling.

Mandatory Part

    Function Name: get_next_line

    Prototype:

    c

    char *get_next_line(int fd);

    Description:
        Reads and returns the next line from a file descriptor fd.
        Successive calls to get_next_line should return the next line in the file.
        If an error occurs or if there are no more lines, the function returns NULL.

    External Functions Allowed: read, malloc, free

    Files:
        get_next_line.c
        get_next_line_utils.c
        get_next_line.h

Bonus Part

If you complete the mandatory part successfully, you can implement the bonus features:

    Manage multiple file descriptors simultaneously.
    Use only one static variable.

Bonus files:

    get_next_line_bonus.c
    get_next_line_utils_bonus.c
    get_next_line_bonus.h

How to Use

    Include the Header File: Make sure you include get_next_line.h in your source code.
    Function Call:

    c

    char *line = get_next_line(fd);

Compilation

Compile your code with the following flags:

bash

cc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c -o get_next_line

    BUFFER_SIZE: You can define the buffer size when compiling by adding -D BUFFER_SIZE=n where n is the desired size. Example:

    bash

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line

Testing

To test your implementation, you can create a simple text file and use your function to read it line by line:

    Create a text file (e.g., test.txt).
    Use the compiled program to read the file:

    bash

    ./get_next_line test.txt



This project is open-source and available under the MIT License.
