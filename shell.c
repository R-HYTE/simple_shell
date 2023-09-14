#include "main.h"
/**
 * main - main function that executes the shell program.
 * 
 * Returns: Always returns 0.
 */
int main()
{
	char commands[1024];

	while (true)
	{
		display_prompt();

		gets_command(commands, sizeof(commands));

		execute_command(commands);
	}
	return (0);
}
