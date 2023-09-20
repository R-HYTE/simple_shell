#include "0-main.h"
/**
 * main - function that executes the shell program.
 *
 * This function runs an interactive shell. It displays a prompt,
 * gets user input, and executes the entered command.
 *
 * Return: Always returns 0
 */
int main(void)
{
	char commands[1024];

	/* Infinite loop for the shell */
	while (true)
	{
		/* Display the shell prompt */
		display_prompt();

		/* Gets user input */
		gets_command(commands, sizeof(commands));

		/* Execute the entered command */
		execute_command(commands);
	}
	return (0);
}
