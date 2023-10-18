#include "shell.h"

/**
 * display_prompt - Displays the shell prompt.
 *
 * Description: This function displays the shell prompt to the user.
 */
void display_prompt(void)
{
	printf("$ ");
}

/**
 * getline_custom - Reads a line of input from the user.
 *
 * Description: This function reads a line of input from the user.
 *
 * Return: The input string.
 */
char *getline_custom(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		exit_shell();
	}
	return (line);
}
