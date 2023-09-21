#include "main.h"
/**
 * Entry - point of the program
 *
 */
int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = my_getline(&line, &len, STDIN_FILENO)) != -1)
	{
		printf("%s", line);
	}
	free(line);
	return (0);
}
