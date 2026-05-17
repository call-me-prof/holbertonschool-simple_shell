#ifndef SHELL_H
#define SHELL_H
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
extern char **environ;
 
char *find_path(char *cmd);
char **tokenize(char *line);
void execute(char **args);
 
#endif
