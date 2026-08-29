# Simple Shell Programming Project #

A lightweight command-line shell written in **C**, designed to run directly on **Windows using MSYS2**. No Linux installation is required.

## Project Overview

This project demonstrates the basic ideas behind a command-line shell:

- Read user input
- Recognize built-in commands
- Change and display the working directory
- Keep a command history
- Execute external commands
- Display a user-friendly prompt
- Handle invalid directory changes without crashing

## Features

| Command | Purpose |
|---|---|
| `help` | Displays all supported commands |
| `cd <dir>` | Changes the current directory |
| `pwd` | Shows the current directory |
| `echo <text>` | Prints text |
| `history` | Shows previous commands |
| `clear` | Clears the terminal |
| `exit` | Exits the shell |
| Any external command | Passes it to the system command processor |

## Technologies

- C
- Standard C libraries
- MSYS2 terminal
- GCC compiler
- VS Code

## Folder Structure

```text
simple-shell-project/
├── shell.c
├── README.md
├── TECHNICAL_REPORT.md
├── DEMO_SCRIPT.md
└── .gitignore
```

## How to Build on Windows with MSYS2

Open **MSYS2 UCRT64** (or the MSYS2 terminal you normally use) and move to the project folder.

Compile:

```bash
gcc shell.c -o simple-shell.exe
```

Run:

```bash
./simple-shell.exe
```

> This project does not require Ubuntu, WSL, a virtual machine, or any separate Linux installation.

## Suggested Demo

Try these commands:

```text
help
pwd
echo Hello from my shell
cd ..
pwd
history
notepad
exit
```

For the video, demonstrate at least `help`, `pwd`, `echo`, `cd`, `history`, one external command, and `exit`.

## Skills Demonstrated

- C programming
- String processing
- Functions and modular design
- Arrays
- Command parsing
- File-system navigation
- Error handling
- Process/command execution through `system()`
- Debugging and testing
- Git/GitHub project documentation

## Limitations and Future Improvements

This is intentionally a small educational shell. A more advanced version could add:

- Quoted argument parsing
- Pipes such as `dir | findstr .c`
- Input/output redirection
- Environment variables
- Command auto-completion
- Better process management using Windows APIs

