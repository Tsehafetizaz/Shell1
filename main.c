#include "shell.h"

/**
 * main - Main function for the shell.
 * Return: 0 (Success), or exit status of child process.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);

		nread = getline(&line, &len, stdin);

		/* Handle end of file or error */
		if (nread == -1)
		{
			free(line);
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
			perror("./hsh");
			exit(EXIT_FAILURE);
		}

		/* Remove the newline character */
		line[nread - 1] = '\0';

		exec_command(line);
	}

	free(line);
	return (EXIT_SUCCESS);
}
