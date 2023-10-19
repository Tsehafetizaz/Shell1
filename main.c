#include "shell.h"

/**
 * main - Main function for the shell.
 * Return: 0 (Success), or exit status of child process.
 */

int main(void)
{
	char *input;
char **args;

	while (1)
	{
		printf("($) ");
		input = my_getline();
		args = parse_input(input);
		if (check_builtin(args) == 0)
		{
			execute_command(args);
		}
		free_args(args);
	}
	return (0);
}
