#include "main.h"

/**
 * get_sigint - Handle the crtl + c call in prompt
 * @sig: Signal handler
 * Return: void
 */
void get_sigint(int sig)
{
	(void)sig; /*Suppress "unused variable" warning*/
	write(STDOUT_FILENO, "\n($) ", 5);
}
