#include "shell.h"

/**
 * main - The main loop of the shell.
 * @argc: Argument count.
 * @argv: Argument vector.
 * @env: Environment variables.
 *
 * Return: Always 0 (success).
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	ssize_t read;
	(void)argc;
	(void)argv;
	(void)env;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}

		args = tokenize(line);
		execute_command(args);

		free(line);
		line = NULL;
		free(args);
	}

	return (0);
}
