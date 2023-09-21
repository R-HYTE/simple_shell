#include "main.h"
#define COUNT_MAX 108 /* Difines suitable value */
/**
 * gets_command - reads a command from stdin into the provided buffer.
 *
 * @commands: Pointer to the buffer where the command will be stored.
 *
 * @size: Size of the buffer.
 */
void gets_command(char **commands, size_t *size)
{
	char *copys = NULL;
	char token_of_args[COUNT_MAX];
	ssize_t chars_read;
	int counts_tokens = 0;


	chars_read = getline(commands, size, stdin);

	if (chars_read == -1)
	{
		fprintf(stderr, "No such file or directory\n");
		exit(EXIT_FAILURE);
	}
	commands[chars_read - 1] = '\0';

	if (strcmp(*commands, "exit") == 0)
		exit(EXIT_SUCCESS);
	copys = strdup(*commands);

	if (!copys)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}

	token_input(copys, token_of_args, &counts_tokens);

	if ( counts_tokens > 0)
	{
		execute(token_of_args);
	}
	free(copy);

}
