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

	while (1)
	{
		printf(": ) ");
		line = read_line();
		if (!line || feof(stdin))
		{
			if (line)
			{
				free(line);
			}
			break;
		}
		args = split_line(line);
		execute_command(args);
		free(line);
		free(args);
	}
	return (0);
}
