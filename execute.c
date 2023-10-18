#include "shell.h"

/**
 * execute_command - Executes the given command.
 * @args: Tokenized arguments.
 *
 * Description: This function tries to execute a command.
 * If the command is found in the PATH, it's executed.
 * Otherwise, an error message is printed.
 */
void execute_command(char **args)
{
char *cmd_path = find_in_PATH(args[0]);
if (cmd_path)
{
execve(cmd_path, args, environ);
}
else
{
perror(args[0]);
}
}
