#include "shell.h"

/**
 * execute_command - Executes the provided command.
 * @args: Null-terminated list of arguments.
 * args[0] should be the command.
 * Return: 1 on success, -1 on failure.
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *path_command = NULL;

	if (args[0] == NULL)
	{
		return;
	}
	if (is_builtin(args[0]))
	{
		execute_builtin(args);
		return;
	}
	if (args[0][0] != '/')
	{
		path_command = search_in_PATH(args[0]);
		if (path_command == NULL)
		{
			fprintf(stderr, "%s: No such file or directory\n", args[0]);
			return;
		}
		args[0] = path_command;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("shell");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (path_command)
	{
		free(path_command);
	}
}
