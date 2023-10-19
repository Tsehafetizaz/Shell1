#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
char **parse_input(char *input);
int execute_command(char **args);
int check_builtin(char **args);
void free_args(char **args);
char *get_path(char *command);
char *my_getline(void);
extern char **environ;

#endif /* SHELL_H */
