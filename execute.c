#include "shell.h"
 
/**
 * execute - finds the command, forks, and executes it
 * @args: array of arguments (NULL-terminated)
 * @prog: name of the shell program (argv[0])
 * @count: command count (for error messages)
 *
 * Return: exit status of the command, or 127 if not found
 */
int execute(char **args, char *prog, int count)
{
	pid_t pid;
	int status;
	char *cmd;
 
	cmd = find_in_path(args[0]);
	if (cmd == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
			prog, count, args[0]);
		return (127);
	}
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd);
		return (1);
	}
 
	if (pid == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			perror(prog);
			free(cmd);
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free(cmd);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
 
	return (0);
}
