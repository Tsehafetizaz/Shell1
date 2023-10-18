#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global variable for environment */
extern char **environ;

/* Function Prototypes */

/* main.c */
int main(void);

/* execute.c */
void execute_command(char **args);

/* utils.c */
char **tokenize(char *line);
char *find_in_PATH(char *cmd);

/* builtins.c */
void execute_builtin(char **args);
void print_env(void);
void exit_shell(void);
int is_builtin(char *cmd);

/* input.c */
void display_prompt(void);
char *getline_custom(void);

#endif /* SHELL_H */
