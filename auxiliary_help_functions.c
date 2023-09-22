#include "main.h"

/**
 * display_help_env - Displays help information for the 'env'
 * Return: void
 */
void display_help_env(void)
{
	char *helpMessage = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));

}

/**
 * display_help_setenv - Display help information for the 'setenv'
 * Return: void
 */
void display_help_setenv(void)
{

	char *helpMessage = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "int replace)\n\t";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
}

/**
 * display_help_unsetenv - Displays help information for the 'unsetenv'
 * Return: void
 */
void display_help_unsetenv(void)
{
	char *helpMessage = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
}

/**
 * display_help_general - Entry point for general help information
 * Return: void
 */
void display_help_general(void)
{
	char *helpMessage = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "unsetenv [variable]\n";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
}

/**
 * display_help_exit - Display Help information fot the builint exit
 * Return: void
 */
void display_help_exit(void)
{
	char *helpMessage = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
	helpMessage = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, helpMessage, _strlen(helpMessage));
}
