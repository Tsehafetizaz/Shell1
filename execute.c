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
 * execute_command - Executes a command
 * @args: Array of arguments
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
pid = fork();

if (pid == 0)
	{
char *cmd_path = search_in_PATH(args[0]);

		if (cmd_path)
		{
			execve(cmd_path, args, NULL);
			free(cmd_path);
		}
		else
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
