#include "main.h"

/**
 * main - entry point for the simple shell
 * @ac: argument count (unused)
 * @av: argument vector (contains program name)
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	(void)ac;

	while (1)
	{
		/* 1. Display prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		/* 2. Read input */
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}

		/* 3. Remove newline character */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* 4. Tokenize and execute */
		args = tokenize(line);
		if (args && args[0])
		{
			execute_cmd(args, av[0]);
		}
		free(args);
	}
	free(line);
	return (0);
}
