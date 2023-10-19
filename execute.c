#include "shell.h"
/*
 * execute_command - Execute the command provided in args.
 * @param args: Array of arguments.
 * @return: 1 if the shell should continue running, 0 if it should terminate.
 */
int execute_command(char **args)
{
	pid_t pid;
	int status = 0;
	pid = fork();

	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("shell");
	}
	else
	{
		/* Parent process */
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			waitpid(pid, &status, WUNTRACED);
		}
	}
	return (1);
}
