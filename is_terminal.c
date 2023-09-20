#include "main.h"

/**
 * is_terminal - Check if a file descriptor is a terminal
 * @fd: File descriptor to check
 * Return: 1 if the file descriptor is a terminal, 0 otherwise
 */
int is_terminal(int fd)
{
	return (isatty(fd));
}
