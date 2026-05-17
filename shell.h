#ifndef SHELL_H
#define SHELL_H
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
 
extern char **environ;
 
/* main.c */
char	**tokenize(char *line);
void	print_env(void);
 
/* execute.c */
int	execute(char **args, char *prog, int count);
 
/* path.c */
char	*_getenv(char *name);
char	*find_in_path(char *cmd);
 
#endif /* SHELL_H */
