#include "main.h"
/**
 *
 */
void token_input(char **commands, char *arg[], int *arg_count)
{
	const char *delimiter = " \n";
	char *token = strtok(commands[i], delimiter);
	int i = 0;


	while (token != NULL)
	{
		arg[i] = strdup(token);
		if (!arg[i])
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, delimiter);
	}

	arg[i] = NULL;
	*argc = i;
}
