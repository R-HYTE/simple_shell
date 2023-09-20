#include "main.h"

/**
 * main - Entry point
 * @argc: word count of input on CLI
 * @argv: argument vector
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	char *prompt = "$ ";
	char *line = NULL, *line_copy = NULL, *token;
	size_t size = 0;
	ssize_t num_of_chars_read;
	const char *delimiter = " \n";
	int token_count, i, j;

	(void)argc;
	while (true)
	{
		printf("%s", prompt); /*Prompt message*/ 
		num_of_chars_read = getline(&line, &size, stdin); /*getline() returns num of characters read*/
		/*get to see if we've reached EOF or Ctrl + D to exit shell*/
		if (num_of_chars_read == -1)
		{
			fprintf(stderr, "Error reading input. Exiting shell\n");
			break;
		}
		line[num_of_chars_read - 1] = '\0';
		if (strcmp(line, "exit") == 0)
		{
			break;
		}
		else if (strcmp(line, "env") == 0)
			print_environment();

		/*Store a copy of what was read from the stdin*/
		line_copy = malloc(sizeof(char) * num_of_chars_read);
		if (line_copy == NULL)
		{
			perror("memory allocation error");
			free(line);
			break;
		}
		strcpy(line_copy, line);
		/*tokenization of the line from the stdin to get number of tokens*/
		/*the string in line gets destroyed in the process*/
		token_count = 0;
		token = strtok(line, delimiter);
		while (token != NULL)
		{
			token_count++;
			token = strtok(NULL, delimiter);
		}
		token_count++; /*We are considering the new line when you press enter*/

		/*Storing actual token in an array*/
		argv = malloc(sizeof(char *) * token_count);
		if (argv == NULL)
		{
			perror("memory allocation error");
			free(line_copy);
			free(line);
			break;
		}

		token = strtok(line_copy, delimiter);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token) + 1);
			if (argv[i] == NULL)
			{
				perror("memory allocation error");
				for (j = 0; j < i; j++)
				{
					free(argv[j]);
				}
				free(argv);
				free(line_copy);
				free(line);
				return (-1);
			}
			strcpy(argv[i], token);
			token = strtok(NULL, delimiter);
		}
		argv[i] = NULL;

		/*Executing these commands*/
		execute(argv);

		for (j = 0; j < i; j++)
		{
			free(argv[j]);
		}
		free(argv);

		free(line_copy);

	}
	free(line);/*free the dynamic memory being occupied thanks to the getline() operations*/

	return (0);
}
