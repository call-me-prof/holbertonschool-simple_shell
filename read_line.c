#include "shell.h"

/**
 * read_line - reads one line from stdin
 *
 * Return: pointer to line (caller must free), NULL on EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t len;

	len = getline(&line, &n, stdin);
	if (len == -1)
	{
		free(line);
		return (NULL);
	}

	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';

	return (line);
}
