#include "shell.h"

/**
 * tokenize - Tokenizes a string based on spaces.
 * @line: The input string.
 *
 * Description: This function tokenizes the input string.
 *
 * Return: Array of tokens.
 */
char **tokenize(char *line)
{
	char **tokens = NULL;
	int token_count = 0;
	char *token = strtok(line, " ");

tokens = malloc(sizeof(char *) * (token_count + 2));
if (!tokens)
{
perror("Error allocating memory for tokens");
exit(EXIT_FAILURE);
}

	while (token != NULL)
	{
		tokens[token_count] = token;
		token_count++;
		token = strtok(NULL, " ");
	}
	tokens[token_count] = NULL;
	return (tokens);
}

/**
 * find_in_PATH - Searches for a command in the PATH.
 * @cmd: The command to search for.
 *
 * Description: This function searches for a command in the PATH directories.
 *
 * Return: Full path of the command if found, NULL otherwise.
 */
char *find_in_PATH(char *cmd)
{
	char *PATH = getenv("PATH");
	char *dir = strtok(PATH, ":");
	char *cmd_path = malloc(512);  /* Assuming max path length */

	while (dir != NULL)
	{
		sprintf(cmd_path, "%s/%s", dir, cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			return (cmd_path);
		}
		dir = strtok(NULL, ":");
	}
	free(cmd_path);
	return (NULL);
}

/**
 * exit_shell - exits the shell with a given status.
 *
 * This function is used to cleanly exit the shell program with a specified
 * exit status - It wraps the standard `exit` function to provide a more
 * descriptive function name in the context of the shell program.
 *
 * status - the exit status to terminate the shell with.
 */
void exit_shell(int status)
{
	exit(status);
}

