#include "shell.h"
/**
 * read_line - Reads a line from stdin.
 * Description: This function reads a line.
 * Return: The line read from stdin.
 */
char *read_line(void)
{
	char *line = NULL;
size_t len = 0;

getline(&line, &len, stdin);
return (line);
}

/**
 * split_line - Splits a line into an array of arguments.
 * @line: The line to split.
 * Description: This function splits a given line into an array
 * Return: Array of arguments.
 */
char **split_line(char *line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
