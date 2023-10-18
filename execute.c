#include "shell.h"
/* 
 * Executes a given command.
 * 
 * This function forks a child process to execute the command while the parent waits.
 * If the command is not found, it prints an error message.
 *
 * Parameters:
 *   - line: The command to be executed.
 */
void execute_command(char *line)
{
	pid_t child_pid;
	int status;
	char *argv[2];

	line[strlen(line) - 1] = '\0';  /* Remove newline */
	argv[0] = line;
	argv[1] = NULL;

	/* Try to execute the command directly */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execvp(argv[0], argv) == -1)  /* Execute command */
			perror("Error:");
		exit(EXIT_FAILURE);  /* Exit child process if execvp fails */
	}
	else
	{
		wait(&status);
		if (WEXITSTATUS(status) == 127)
		{
			printf("%s: command not found\n", line);
		}
	}
}
