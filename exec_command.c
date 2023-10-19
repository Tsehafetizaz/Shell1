#include "shell.h"

/**
 * exec_command - Execute a command.
 * @command: The command to execute.
 */
void exec_command(char *command)
{
	char *argv[2];
	pid_t child_pid;
	int child_status;

	argv[0] = command;
	argv[1] = NULL;

	/* Create a new process */
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		exit(1);
	}

	if (child_pid == 0)
	{
		/* Child process: Execute the command */
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell");
		}
		exit(1);  /* Exit if execve fails */
	}
	else
	{
		/* Parent process: Wait for the child to finish */
		wait(&child_status);
	}
}

