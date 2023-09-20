#include "main.h"
/**
 *
 */
void get_command(char *commands, size_t size)
{
	if (fgets(commands, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			eugo_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			eugo_print("No such file or directory\n");
			exit(EXIT_FAILURE);
		}

	}
	commands[strcspn(commands, " /n")]= '\0';
}
