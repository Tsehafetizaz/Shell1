#include "shell.h"

/**
 * get_input - Read a line of input from stdin.
 * Return: A pointer to the input string.
 */
char *get_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	/* Removing newline character */
	line[nread - 1] = '\0';

	return (line);
}
