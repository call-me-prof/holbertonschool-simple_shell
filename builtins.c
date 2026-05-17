#include "shell.h"

/**
 * is_builtin - checks if a command is a built-in
 * @cmd: command string
 *
 * Return: 1 if built-in, 0 otherwise
 */
int is_builtin(char *cmd)
{
	if (strcmp(cmd, "exit") == 0)
		return (1);
	if (strcmp(cmd, "env") == 0)
		return (1);
	return (0);
}

/**
 * handle_builtin - executes a built-in command
 * @args: argument array
 *
 * Return: 1 to continue, 0 to exit
 */
int handle_builtin(char **args)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);

	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		return (1);
	}

	return (1);
}
