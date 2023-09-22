#include "myheader.h"

/**
 * display_environment - Prints the environment variables
 * Return: void
 */

void display_environment(void)
{
	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
	}
}
