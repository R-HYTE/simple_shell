#include "main.h"

int main()
{
	const char *prompt = "#cisfun$ ";
	char *line = NULL;
	size_t size = 0;
	ssize_t num_of_chars_read;

	while (1)
	{
		printf("%s", prompt); /* Display prompt */

		num_of_chars_read = getline(&line, &size, stdin);

		/* Check for EOF or Ctrl+D */
		if (num_of_chars_read == -1)
		{
			break;
		}

		/* Remove the newline character from the end */
		if (line[num_of_chars_read - 1] == '\n')
			line[num_of_chars_read - 1] = '\0';

		/* Execute the command */
		execute(line);

	}

	free(line);  /* Free allocated memory */

	return 0;
}
