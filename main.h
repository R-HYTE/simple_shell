#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
ssize_t my_getline(char **lineptr, size_t *n, int fd);

#endif
