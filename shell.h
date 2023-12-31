#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
char *search_in_PATH(char *cmd);
void execute_command(char **args);
int is_builtin(char *command);
void execute_builtin(char **args);
extern char **environ;

#endif /* SIMPLE_SHELL_H */
