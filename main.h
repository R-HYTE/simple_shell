#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int is_terminal(int fd);
void tokenize_input(char *line, char *argv[], int *argc);
void execute(char **argv);
char *find_executable_path(char *command);
void print_environment(void);

extern char **environ;

#endif
