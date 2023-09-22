#include "myheader.h"
/**
 * main - function for the custom shell.
 */
int main(void)
{
	char *prompt, *line = NULL, *line_copy = NULL, *tokens[MAX_ARGS]; /* Initialize pointers and arrays*/
	size_t size = 0; /* Initialize size variable for getline */
	ssize_t chars_read; /* Initialize variable to store number of characters read */
	int token_count = 0, is_term_fd = fileno(stdin), is_term_result = is_terminal_fd(is_term_fd);

	prompt = (is_term_result) ? "$ " : "";
	while (true)
	{
		printf("%s", prompt);
		chars_read = getline(&line, &size, stdin);
		if (chars_read == -1)
		{
			fprintf(stderr, "Error. Exiting.\n"); 
			break; 
		}
		line[chars_read - 1] = '\0';
		if (strcmp(line, "exit") == 0) 
			break;
		line_copy = strdup(line);

		if (!line_copy) { perror("memory allocation error"); 
			break;
		}

		tokenize_input_line(line_copy, tokens, &token_count);

		if (token_count > 0)
			execve(tokens[0], tokens, NULL);
		free(line_copy);
	}
	free(line);
	return 0;
}
