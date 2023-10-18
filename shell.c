#include "shell.h"

/*
 * main function for the simple UNIX command line interpreter.
 * Continuously displays a prompt, reads a command from the use
 *
 * and executes the command.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&line, &len, stdin) == -1)  /* Handle EOF */
		{
			free(line);
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		execute_command(line);
	}
	free(line);
	return (0);
}
