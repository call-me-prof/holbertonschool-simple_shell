# Simple Shell Project
This is a basic command line interpreter written in C for Holberton School.
Simple Shell
Description
Simple Shell is a UNIX command line interpreter written in C.
It recreates a basic shell that executes commands in both interactive
and non-interactive modes.
Compilation
bashgcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Usage
Interactive mode
$ ./hsh
$ /bin/ls
$ exit
Non-interactive mode
echo "/bin/ls" | ./hsh
Files
FileDescriptionmain.cMain loop, tokenizer, env built-inexecute.cFork and execute commandspath.cPATH search and _getenvshell.hHeader — prototypes and includesman_1_simple_shellManual page
Features

Interactive and non-interactive mode
PATH handling
Built-in: exit, env
Error handling (command not found, fork failure)
fork is never called if the command does not exist

Authors

Dhay Aldhwayan
Faisal Alshahrani
