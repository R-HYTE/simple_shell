#include "myheader.h"

/**
 * tokenize_input_line - Tokenizes the input line,
 * based on delimiters and populates the args array
 * @input_line: The input line to tokenize
 * @args: An array to store the tokenized arguments
 * @arg_count: A pointer to an integer to store the number of tokens
 * Return: Void
 */
void tokenize_input_line(char *input_line, char *args[], int *arg_count)
{
	const char *delimiter = " \n";
	char *token = strtok(input_line, delimiter);
	int i = 0;

	while (token != NULL)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			perror("memory allocation error");
			/* Handle memory allocation error */
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, delimiter);
	}

	args[i] = NULL; /* Mark the end of args */
	*arg_count = i; /* Update arg_count with the number of tokens */
}
