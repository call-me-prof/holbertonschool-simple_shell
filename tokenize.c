#include "shell.h"

/**
 * tokenize - split line into tokens
 * @line: input string
 * Return: NULL-terminated array of tokens
 */
char **tokenize(char *line)
{
	char **tokens;
	char *copy, *tok;
	int count = 0, i = 0;

	copy = strdup(line);
	if (!copy)
		return (NULL);

	tok = strtok(copy, " \t");
	while (tok)
	{
		count++;
		tok = strtok(NULL, " \t");
	}
	free(copy);

	if (count == 0)
		return (NULL);

	tokens = malloc((count + 1) * sizeof(char *));
	if (!tokens)
		return (NULL);

	copy = strdup(line);
	tok = strtok(copy, " \t");
	while (tok)
	{
		tokens[i++] = strdup(tok);
		tok = strtok(NULL, " \t");
	}
	tokens[i] = NULL;
	free(copy);

	return (tokens);
}
