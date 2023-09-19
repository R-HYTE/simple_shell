# Simple Shell Program

This is a simple shell program written in C. It provides a basic command-line interface for executing commands and includes a few built-in commands such as `exit` and `env`. The shell allows users to execute external commands and display the current environment variables.

## Features

- Prompting the user with "$ " to enter commands.
- Execution of external commands available in the system's PATH.
- Built-in `exit` command to exit the shell.
- Built-in `env` command to display the current environment variables.

## How to Use

1. Compile the C code using a C compiler (e.g., `gcc`):

```bash
gcc -o shell main.c

