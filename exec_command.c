#include "shell.h"

/**
 * exec_command - Execute a command.
 * @command: The command string.
 */
void exec_command(char *command)
{
	char *argv[BUFSIZE];
	char *token;
	int i = 0;
	pid_t child_pid;
	int child_status;

	token = strtok(command, " ");
	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

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
