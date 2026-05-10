#include "main.h"

/**
 * tokenize - splits a string into an array of strings
 * @line: the input string from getline
 * Return: pointer to the array of strings (tokens)
 */
char **tokenize(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (!tokens)
		return (NULL);

	token = strtok(line, " \t\n\r");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t\n\r");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * execute_cmd - creates a child process and executes a command
 * @args: array of command and arguments
 * @prog_name: name of the shell (for error messages)
 */
void execute_cmd(char **args, char *prog_name)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork Error");
		return;
	}

	if (child_pid == 0) /* Child process */
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(prog_name);
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		wait(&status);
	}
}
