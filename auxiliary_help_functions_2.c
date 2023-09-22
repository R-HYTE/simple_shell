#include "main.h"

/**
 * display_help - Displays help information for the 'help'
 * Return: void
 */
void display_help(void)
{
	char *helpMessage = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
}
/**
 * display_help_alias - Displays help information for the 'alias'
 * Return: void
 */
void display_help_alias(void)
{
	char *helpMessage = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
}
/**
 * display_help_cd - Displays help information for the 'cd'
 * Return: void
 */
void display_help_cd(void)
{
	char *helpMessage = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
}
