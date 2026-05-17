#include "shell.h"
 
/**
 * find_path - find full path of command using PATH
 * @cmd: command name
 * Return: full path or NULL if not found
 */
char *find_path(char *cmd)
{
	char *path_val, *path_copy, *dir, *full;
	int i;
 
	/* if cmd has '/', check directly */
	if (strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (strdup(cmd));
		return (NULL);
	}
 
	/* search PATH env variable */
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_val = environ[i] + 5;
 
			if (path_val[0] == '\0')
				return (NULL);
 
			path_copy = strdup(path_val);
			if (!path_copy)
				return (NULL);
 
			dir = strtok(path_copy, ":");
			while (dir)
			{
				full = malloc(strlen(dir) + strlen(cmd) + 2);
				if (!full)
				{
					free(path_copy);
					return (NULL);
				}
				sprintf(full, "%s/%s", dir, cmd);
 
				if (access(full, X_OK) == 0)
				{
					free(path_copy);
					return (full);
				}
				free(full);
				dir = strtok(NULL, ":");
			}
			free(path_copy);
			return (NULL);
		}
	}
	return (NULL);
}
 
/**
 * execute - execute a command
 * @args: argument array
 */
void execute(char **args)
{
	pid_t pid;
	int status;
	char *path;
 
	/* Find command BEFORE forking */
	path = find_path(args[0]);
	if (!path)
	{
		fprintf(stderr, "./shell: %s: not found\n", args[0]);
		return;
	}
 
	/* Only fork if command exists */
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(path);
		return;
	}
 
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("execve");
			free(path);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
	free(path);
}
