#include "shell.h"

/**
 * find_in_PATH - Search for a command in the PATH directories.
 * @cmd: The command to search for.
 * Return: Full path to the command if found, NULL otherwise.
 */
char *find_in_PATH(char *cmd)
{
	char *PATH;
	char *dir;
	char *full_path;

	/* Get the PATH environment variable */
	PATH = getenv("PATH");
	if (!PATH)
	{
		return (NULL);
	}

	/* Allocate memory for the full path */
	full_path = malloc(512); /* Arbitrary size, adjust as needed */
	if (!full_path)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	dir = strtok(PATH, ":");
	while (dir)
	{
		snprintf(full_path, 512, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}

	free(full_path);
	return (NULL);
}

#ifdef TEST_PATH_UTILS
int main(void)
{
	char *input;
	char **args;
	char *cmd_path;

	while (1)
	{
		printf("($) ");
		input = my_getline();
		args = parse_input(input);

		if (check_builtin(args) == 0)
		{
			cmd_path = find_in_PATH(args[0]);
			if (cmd_path)
			{
				free(args[0]);
				args[0] = cmd_path;
				execute_command(args);
			}
			else
			{
				printf("%s: command not found\n", args[0]);
			}
		}

		free(input);
		free_args(args);
	}
	return (0);
}
#endif
