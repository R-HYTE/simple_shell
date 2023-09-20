#include "main.h"

/**
 * print_environment - Prints te environment variables
 * Return: void
 */

void print_environment(void)
{
	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
	}
}
