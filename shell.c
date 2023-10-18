include "shell.h"

/*
* Function: main
* Main function for the shell loop.
* Displays a prompt, reads user input, and executes commands.
* Returns:
* 0 on success.
*/
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		read = getline(&line, &len, stdin);
		if (read == -1)  /* Handle EOF (Ctrl+D) */
		{
			write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}

		line[read - 1] = '\0';  /* Remove newline */
		execute_command(line);
	}
	free(line);
	return (0);
}
/*
 * Function: execute_command
 *
 * Executes a given command.
 * Forks a child process to run the command and waits for its completion.
 *
 * Parameters:
 * command: The command to execute.
 */
void execute_command(char *command)
{
	pid_t child_pid;
	int status;

	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./shell");
		return;
	}
	if (child_pid == 0)  /* Child process */
	{
		char *argv[] = {command, NULL};

		if (execve(command, argv, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else  /* Parent process */
	{
		wait(&status);
	}
}
