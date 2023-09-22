#ifndef MAIN_H
#define MAIN_H

/* all of the header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>


extern char **environ;
char *find_command_path(char *command);
void execute_command(char **args);
void display_environment(void);
int is_terminal_fd(int fd);
void tokenize_input_line(char *input_line, char *args[], int *arg_count);
char **str_split(char *str, const char delim);

#endif /* MAIN_H */
