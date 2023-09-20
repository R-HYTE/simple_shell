#include "main.h"
#define MAX_ARG_COUNT 100 /* Define a suitable value for MAX_ARG_COUNT */

/**
 * main - Entry point
 * Return: 0 (Success)
 */
int main(void)
{
	char *prompt = "$ ";
	char *line = NULL, *line_copy = NULL, *tokenized_args[MAX_ARG_COUNT];
	size_t size = 0;
	ssize_t num_of_chars_read;
	int token_count = 0;

	while (true)
	{
		printf("%s", prompt);
		num_of_chars_read = getline(&line, &size, stdin);

		if (num_of_chars_read == -1)
		{
			fprintf(stderr, "Error reading input. Exiting shell\n");
			break;
		}
		line[num_of_chars_read - 1] = '\0';

		if (strcmp(line, "exit") == 0)
			break;
		line_copy = strdup(line);
		if (!line_copy)
		{
			perror("memory allocation error");
			break;
		}
		tokenize_input(line_copy, tokenized_args, &token_count);

		if (token_count > 0)
		{
			execute(tokenized_args);
		}
		free(line_copy);
	}
	free(line);
	return (0);
}

