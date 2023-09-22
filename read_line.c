#include "main.h"

/**
 * read_user_input - Reads a line of input from the user
 * @eof_flag: Pointer to store the end-of-file flag (1 if EOF, 0 otherwise)
 * Return: The input string read from user
 */
char *read_user_input(int *eof_flag)
{
	char *input_buffer = NULL;
	size_t bufsize = 0;

	*eof_flag = getline(&input_buffer, &bufsize, stdin);

	return (input_buffer);
}
