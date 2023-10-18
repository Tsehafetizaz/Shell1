#include "shell.h"

/**
 * is_builtin - Checks if a command is a built-in.
 * @cmd: The command to check.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int is_builtin(char *cmd)
{
	char *builtins[] = {"env", "exit", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (strcmp(cmd, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * execute_builtin - Executes a built-in command.
 * @args: The arguments for the command.
 */
void execute_builtin(char **args)
{
if (strcmp(args[0], "env") == 0)
{
int i;
for (i = 0; environ[i]; i++)
printf("%s\n", environ[i]);
}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
}
