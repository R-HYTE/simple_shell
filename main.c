#include "main.h"
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
	char **commands = NULL;
	size_t size = 0;

	/* Infinite loop for the shell */
	while (true)
	{
		/* Display the shell prompt */
		display_prompt();

		/* Gets user input */
		gets_command(commands, &size);

		/* Execute the entered command */
		execute_commands(commands[0]);

		token_input(commands, NULL, NULL);
	}
	free(commands);
	return (0);
}
