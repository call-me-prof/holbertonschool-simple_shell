#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* Prototypes */
void execute_cmd(char **args, char *prog_name);
char **tokenize(char *line);

#endif
