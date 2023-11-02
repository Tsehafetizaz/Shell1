#include "shell.h"
/**
 * search_in_PATH - Searches for a command in the PATH
 * @cmd: The command to search for
 *
 * Return: Full path to the command, or NULL if not found
 */
char *search_in_PATH(char *cmd)
{
	char *PATH = getenv("PATH");
	char *dir = strtok(PATH, ":");
	char *full_path = malloc(512);

	if (!full_path)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}
	while (dir != NULL)
	{
		sprintf(full_path, "%s/%s", dir, cmd);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		dir = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}
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

	if (args[0] == NULL)
	{
		/* An empty command was entered. */
		return;
	}
	if (is_builtin(args[0]))
	{
		execute_builtin(args);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("shell");
	}
	else
	{
		/* Parent process */
		do	{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
