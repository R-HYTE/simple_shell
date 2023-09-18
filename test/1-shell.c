#include "main.h"
/**
 * main - main function that executes the shell program.
 *
 * Return: Always 0
 */
int main(void)
{
	char commands[1024];

	while (true)
	{
		display_prompt();

		get_command(commands, sizeof(commands));

		execute();


	}
	return (0);
}
