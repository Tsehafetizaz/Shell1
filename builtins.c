#include "shell.h"
#include <unistd.h>

/**
 * is_builtin - Checks if a command is a built-in
 * @cmd: The command to check
 *
 * Return: 1 if it's a built-in, 0 otherwise
 */
int is_builtin(char *cmd)
{
	char *builtins[] = {"exit", "env", NULL};
int i = 0;

	while (builtins[i])
	{
		if (strcmp(cmd, builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
/**
 * execute_builtin - Executes a built-in command
 * @args: Array of arguments
 */
void execute_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		exit(0);
	}
else if (strcmp(args[0], "env") == 0)
	{
char **env = environ;

			while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}

