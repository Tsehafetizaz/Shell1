#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "
#define BUFSIZE 1024

/* Function Prototypes */
char *get_input(void);
void exec_command(char *command);

#endif /* SHELL_H */
