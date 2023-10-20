#include "shell.h"
/**
 * main - Entry point of the shell.
 * Description: This function initializes the shell
 * and then executes the command.
 * Return: 0 on success.
 */
int main(void)
{
	char *line;
	char **args;

	printf(": ) ");
	line = read_line();
	args = split_line(line);
	execute_command(args);
	free(line);
	free(args);
	return (0);
}
