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


/* 0-shell.c prototypes */
void eugo_print(const char *answer);
void display_prompt(void);
void execute_command(const char *commands);
void gets_command(char *commands, size_t size);

/* 1-shell.c prototypes */
void display_prompt(void);
void eugo_print(const char *answer);
void execute();
void get_command(char *commands, size_t size);
void eugo_print(const char *answer);
#endif /* MAIN_H */
