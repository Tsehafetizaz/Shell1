#include "shell.h"
#include "path_handling.h"
#include <sys/stat.h>

/**
 * execute_command - Executes a command with arguments
 * @args: Null-terminated list of arguments (the command and its parameters)
 *
 * This function first checks if the command exists in the PATH. If it does,
 * it creates a child process using fork and executes the command using execv.
 * It handles commands with arguments and ensures that the parent process waits
 * for the child process to finish execution. If the command is not found,
 * it prints an error message and returns without forking.
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path;

	if (args[0] == NULL)
	{
		/* No command entered */
		return;
	}

	cmd_path = find_command_in_path(args[0]);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: Command not found\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execv(cmd_path, args) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Forking error */
		perror("shell");
	}
	else
	{
		do	{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(cmd_path);
}
