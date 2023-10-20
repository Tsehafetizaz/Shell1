#include "shell.h"

/**
 * main - Entry point of the shell
 * Return: 0 on success
 */
int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		printf(": ) ");
		line = read_line();
		args = split_line(line);
		execute_command(args);

		free(line);
		free(args);
	}
	return (0);
}

/**
 * read_line - Reads a line from stdin
 * Return: The line read
 */
char *read_line(void)
{
		char *line = NULL;
size_t len = 0;

getline(&line, &len, stdin);
return (line);
}

/**
 * split_line - Splits a line into an array of arguments
 * @line: The line to split
 * Return: Array of arguments
 */
char **split_line(char *line)
{
	int bufsize = 64, position = 0;
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

/**
 * search_in_PATH - Searches for a command in the PATH
 * @cmd: The command to search for
 * Return: Full path to the command, or NULL if not found
 */
char *search_in_PATH(char *cmd)
{
	char *PATH = getenv("PATH");
	char *dir = strtok(PATH, ":");
	char *full_path = malloc(512);

	while (dir != NULL)
	{
		sprintf(full_path, "%s/%s", dir, cmd);
		if (access(full_path, F_OK) == 0)
		return (full_path);
		dir = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}

/**
 * execute_command - Executes a command
 * @args: Array of arguments
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		char *cmd_path = search_in_PATH(args[0]);

		if (cmd_path)
		{
			execve(cmd_path, args, NULL);
			free(cmd_path);
		}
		else
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{

		perror("Error");
	}
	else
{
	while (!WIFEXITED(status) && !WIFSIGNALED(status))
	{
		waitpid(pid, &status, WUNTRACED);
	}
}
}
