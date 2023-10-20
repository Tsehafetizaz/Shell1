#include "shell.h"

/**
 * main - Entry point of the shell
 * Description: Main loop of the shell. Reads a line, splits it into arguments,
 * and executes the command.
 * Return: 0 on success
 */
int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		printf("cisfun$  ");
		line = read_line();
		if (!line)  /* Handle EOF (Ctrl+D) */
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		args = split_line(line);
		execute_command(args);

		free(line);
		free(args);
	}

	return (0);
}

/**
 * read_line - Reads a line from stdin
 * Description: Reads a line from standard input and returns it. If EOF is
 * encountered, it returns NULL.
 * Return: The line read or NULL if EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)  /* Check for EOF */
	{
		free(line);
		return (NULL);
				}
				return (line);
				}

/**
 * split_line - Splits a line into an array of arguments
 * @line: The line to split
 * Description: Splits the given line into an array of arguments. For the
 * simple shell 0.1 version, the entire line is treated as a single command.
 * Return: Array of arguments
 */
				char **split_line(char *line)
				{
				char **tokens = malloc(2 * sizeof(char *));

				if (!tokens)
				{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
				}

				tokens[0] = line;  /* Command is the entire line */
				tokens[1] = NULL;  /* NULL-terminate the array */

				return (tokens);
				}

