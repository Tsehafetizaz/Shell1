#include "shell.h"
#include <limits.h>
#include <string.h>
#include <unistd.h>

/**
 * search_in_PATH - Searches for a command in the PATH environment variable.
 * @cmd: The command to search for.
 *
 * Description: This function searches for the given command in the directories
 * specified in the PATH environment variable. If it finds an executable file
 * with the name 'cmd', it returns the full path to that file. Otherwise,
 * it returns NULL.
 *
 * Return: Full path to the command, or NULL if not found.
 */
char *search_in_PATH(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy;
	char *dir;
	char *full_path;

	path_copy = strdup(path);  /* Duplicate the PATH string */
	if (!path_copy)
	{
		perror("Allocation error");
		return (NULL);
	}

	full_path = malloc(PATH_MAX);  /* Allocate memory for the full path */
	if (!full_path)
	{
		perror("Allocation error");
		free(path_copy);
		return (NULL);
	}

	for (dir = strtok(path_copy, ":"); dir != NULL; dir = strtok(NULL, ":"))
	{
		sprintf(full_path, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)  /* Check if command is executable */
		{
			free(path_copy);
			return (full_path);  /* Return the full path if command is found */
		}
	}

	free(full_path);
	free(path_copy);
	return (NULL);  /* Return NULL if command is not found */
}
