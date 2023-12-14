#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char **tokenize(char *str, const char *delim);
void free_command(char **command);
int execute(char **command);
void get_path(char **command);
char *getInput(char **line);
char *my_getenv(char *var);
void my_env(void);
void exit_builtin(void);

#endif
