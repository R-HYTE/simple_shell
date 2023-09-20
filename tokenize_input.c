#include "main.h"

/**
 * tokenize_input - Tokenizes the input line,
 * based on delimiters and populates the argv array
 * @line: The input line to tokenize
 * @argv: An array to store the tokenized arguments
 * @argc: A pointer to an integer to store the number of tokens
 * Return: Void
 */
void tokenize_input(char *line, char *argv[], int *argc)
{
	const char *delimiter = " \n";
	char *token = strtok(line, delimiter);
	int i = 0;

	while (token != NULL)
	{
		argv[i] = strdup(token);
		if (!argv[i])
		{
			perror("memory allocation error");
			/* Handle memory allocation error */
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, delimiter);
	}

	argv[i] = NULL; /* Mark the end of argv */
	*argc = i; /* Update argc with the number of tokens */
}

