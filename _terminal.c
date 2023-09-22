#include "myheader.h"

/**
 * is_terminal_fd - Check if a file descriptor is a terminal
 * @fd: File descriptor to check
 * Return: 1 if the file descriptor is a terminal, 0 otherwise
 */
int is_terminal_fd(int fd)
{
	return (isatty(fd));
}
