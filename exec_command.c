#include "shell.h"

/**
 * exec_command - Execute a single-word command.
 * @command: The command string.
 */
void exec_command(char *command)
{
	pid_t child_pid;
	int child_status;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	/* Create a new process */
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("./shell");
		exit(1);
	}

	if (child_pid == 0)
	{
		/* Child process: Execute the command */
		if (execve(command, argv, NULL) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		/* Parent process: Wait for the child to finish */
		wait(&child_status);
	}
}
