#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * Description: This is the main loop of the shell.
 *
 * Return: 0 on success.
 */
int main(void)
{
char *line;
char **args;

while (1)
{
display_prompt();
line = getline_custom();
args = tokenize(line);
if (is_builtin(args[0]))
{
execute_builtin(args);
}
else
{
execute_command(args);
}
free(line);
free(args);
}
return (0);
}
