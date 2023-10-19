#include "shell.h"

/*
 * Check if the command is a built-in.
 * @param args: Array of arguments.
 * @return: 1 if the command is a built-in, 0 otherwise.
 */
int check_builtin(char **args)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1])
		{
		exit(atoi(args[1]));
		}
		else
		{
			exit(0);
		}
	}
	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
		printf("%s\n", environ[i]);
		}
		return (1);
	}
	return (0);
}
