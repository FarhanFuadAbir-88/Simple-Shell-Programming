# Technical Report — Simple Shell Programming

## 1. Project Title

**Simple Shell Programming**

## 2. Project Objective

The objective of this project was to create a small command-line shell in C that accepts commands from a user, processes built-in commands, and executes external commands. The project was developed and tested on Windows using MSYS2 and VS Code.

## 3. System / Tools

- Operating System: Windows
- IDE/Editor: Visual Studio Code
- Terminal/Build Environment: MSYS2
- Compiler: GCC
- Programming Language: C

No separate Linux operating system or Linux virtual machine was required.

---

# 4. Challenges Using STAR Format

## Challenge 1 — Designing the command-processing loop

### Situation
A shell needs to continuously display a prompt, receive input, decide what the user wants, and then repeat until the user exits. The challenge was to keep this process simple while avoiding crashes on empty input.

### Task
I needed to create the main interactive loop for the shell and connect it with command handling.

### Action
I created a loop in `main()` that:
1. Displays the current working directory as the prompt.
2. Reads a line with `fgets()`.
3. Removes the newline character.
4. Ignores empty input.
5. Stores valid commands in history.
6. Sends the command to the built-in command handler.
7. Executes unknown commands through `system()`.

### Result
The shell now behaves interactively like a basic command-line environment. It continues accepting commands until the user enters `exit`.

---

## Challenge 2 — Handling built-in commands

### Situation
Commands such as `cd` cannot simply be executed as separate processes because the shell itself needs to change its current working directory.

### Task
I needed to implement common shell commands directly inside the program.

### Action
I added a `handle_builtin()` function that recognizes:
- `cd`
- `pwd`
- `echo`
- `history`
- `clear`
- `help`
- `exit`

For directory operations, the Windows-compatible `_chdir()` and `_getcwd()` functions were used.

### Result
The shell can change directories and maintain the new location for later commands. This also makes the prompt update automatically after `cd`.

---

## Challenge 3 — Keeping a useful command history

### Situation
A command shell becomes easier to demonstrate and use when previous commands can be reviewed.

### Task
I wanted to add history without making the project unnecessarily complex.

### Action
I created a fixed-size two-dimensional character array capable of storing up to 50 commands. Every non-empty command is copied into the history array. When the array is full, the oldest command is removed to make space for the newest one.

### Result
The `history` command displays previously entered commands with numbers. This demonstrates arrays, string handling, and basic data management.

---

## Challenge 4 — Making the project work on Windows

### Situation
Many shell tutorials assume Linux-specific tools or APIs. My development environment was Windows with MSYS2, and I wanted to avoid installing another operating system or Linux environment.

### Task
I needed a version that could compile and run directly in MSYS2 on Windows.

### Action
I used GCC supplied by MSYS2 and Windows-compatible C functions such as `_chdir()` and `_getcwd()`. External commands are delegated through C's `system()` function. The project documentation also gives Windows/MSYS2-specific build instructions.

### Result
The project can be compiled as a Windows executable with:

```bash
gcc shell.c -o simple-shell.exe
```

and launched with:

```bash
./simple-shell.exe
```

No separate Linux installation is required.

---

# 5. Implementation Summary

The program follows a simple architecture:

```text
Start
  |
  v
Display prompt
  |
  v
Read command
  |
  v
Save to history
  |
  v
Is it a built-in command?
  |              |
 Yes             No
  |              |
  v              v
Run handler    Run external
  |            command
  |              |
  +------<-------+
  |
  v
Repeat
  |
  v
exit -> End
```

The main programming concepts used are functions, loops, arrays, strings, conditional statements, error handling, and command execution.

---

# 6. Testing

The following test cases should be demonstrated:

| Test | Expected Result |
|---|---|
| `help` | Shows command list |
| `pwd` | Prints current directory |
| `echo Hello` | Prints `Hello` |
| `cd ..` | Moves to parent directory |
| `history` | Shows previously entered commands |
| Invalid `cd` | Displays an error without crashing |
| External command | Executes through the system |
| `exit` | Closes the shell |

## Example Test Session

```text
simple-shell:C:\...\simple-shell-project> help

Simple Shell - available commands
----------------------------------
cd <dir>       Change the current directory
pwd            Print the current directory
echo <text>    Print text
history        Show previously entered commands
clear          Clear the terminal screen
help           Show this help message
exit           Close the shell

simple-shell:C:\...\simple-shell-project> echo Hello World
Hello World

simple-shell:C:\...\simple-shell-project> pwd
C:\...\simple-shell-project

simple-shell:C:\...\simple-shell-project> history
 1  help
 2  echo Hello World
 3  pwd
 4  history
```

---

# 7. Skills Highlighted

- C programming
- Command-line application development
- String manipulation
- Arrays and functions
- Basic file-system navigation
- Error handling
- Debugging
- Testing
- Git and GitHub documentation
- Technical communication

---

# 8. Conclusion

The Simple Shell project successfully demonstrates the core concept of an interactive command-line shell in a small and understandable C program. The project was intentionally kept compact so that each component can be explained during the demonstration.

The final program accepts commands, supports several built-in shell functions, maintains command history, handles directory changes, and executes external commands. It also demonstrates how a C program can provide shell-like functionality on Windows using MSYS2 without requiring a separate Linux installation.

# 9. GitHub Repository

Repository name:

**simple-shell-programming**

Repository URL:

https://github.com/FarhanFuadAbir-88/Simple-Shell-Programming

The GitHub repository contains the source code, build instructions, project explanation, technical report, and demonstration instructions.
