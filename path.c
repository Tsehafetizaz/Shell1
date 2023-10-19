#include "shell.h"
/*
 * path - get the full path of a command.
 * param command: The command for which the full path is to be found.
 * return: A string containing the full path of the command.
 */
char *get_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char *full_path = malloc(512); /* Arbitrary size for demonstration */

	while (token != NULL)
	{
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	free(full_path);
	return (command);
}
