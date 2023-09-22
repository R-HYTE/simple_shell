#ifndef MYHEADER_H
#define MYHEADER_H
#define MAX_ARGS 108 /*MAX_BUFFER_OF_ARGS*/

/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
char *find_command_path(char *command);
void execute_command(char **args);
void display_environment(void);
int is_terminal_fd(int fd);
void tokenize_input_line(char *input_line, char *args[], int *arg_count);

#endif /* END OF MYHEADER FILE */
