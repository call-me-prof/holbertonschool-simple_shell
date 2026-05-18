# Simple Shell 

A simple UNIX command line interpreter written in C for Holberton School.

## Description

**hsh** is a simple shell that mimics the behavior of `/bin/sh`. It reads commands from the user (interactive mode) or from a file/pipe (non-interactive mode), parses them, and executes them.

## Requirements

- Ubuntu 20.04 LTS
- gcc compiler
- Libraries: `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<unistd.h>`, `<sys/types.h>`, `<sys/wait.h>`

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive mode
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.h
($) exit
$
```

### Non-interactive mode
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.h
$ cat test
/bin/ls
/bin/pwd
$ cat test | ./hsh
hsh main.c shell.h
/home/user/holbertonschool-simple_shell
```

## Built-in Commands

| Command | Description |
|---------|-------------|
| `exit` | Exit the shell |
| `env`  | Print the current environment |

## Files

| File | Description |
|------|-------------|
| `main.c` | Main loop, tokenizer, env built-in |
| `execute.c` | Fork and execute commands |
| `path.c` | PATH search and `_getenv` |
| `builtins.c` | Built-in commands (exit, env) |
| `read_line.c` | Read input line |
| `shell.h` | Header — prototypes and includes |
| `man_1_simple_shell` | Manual page |

## How It Works

1. Displays a prompt `($) `
2. Reads the user's input
3. Tokenizes the input into arguments
4. Searches for the command in PATH
5. Forks a child process and executes the command
6. Waits for the child to finish, then repeats

## Authors

- Faisal Alshahrani , (call-me-prof)
- Dhay Aldhwayan , (d404cjebq)

