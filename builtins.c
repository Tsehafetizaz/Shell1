#include "shell.h"

/**
 * execute_builtin - Executes a built-in command.
 * @args: Tokenized arguments.
 *
 * Description: This function executes a built-in command.
 */
void execute_builtin(char **args)
{
	if (strcmp(args[0], "env") == 0)
	{
		print_env();
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit_shell();
	}
}

/**
 * print_env - Prints the environment variables.
 *
 * Description: This function prints the environment variables.
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
/**
 * is_builtin - Checks if a command is a built-in.
 * @cmd: The command to check.
 * 
 * Return: 1 if it's a built-in, 0 otherwise.
 */
int is_builtin(char *cmd)
{
	if (strcmp(cmd, "env") == 0 || strcmp(cmd, "exit") == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * exit_shell - Exits the shell.
 *
 * Description: This function exits the shell.
 */
void exit_shell(void)
{
	exit(0);
}
