#include "shell.h"

/**
 * main - entry point for simple shell
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, ":) ", 3);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			return (0);
		}

		line[read - 1] = '\0';

		if (line[0] == '\0')
			continue;

		args = tokenize(line);
		if (!args)
			continue;

		execute(args);
		free(args);
	}

	free(line);
	return (0);
}
