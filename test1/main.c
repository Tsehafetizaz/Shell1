#include "shell.h"

/**
 * main - Entry point of our shell.
 * Return: Always 0.
 */
int main(void)
{
	char *line;

	while (1)
	{
		printf(PROMPT);
		line = get_input();

		/* Handling EOF (Ctrl+D) */
		if (!line)
		{
			printf("\n");
			exit(0);
		}

		exec_command(line);
		free(line);
	}
	return (0);
}
