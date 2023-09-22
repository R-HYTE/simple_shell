#include "main.h"

/**
 * get_builtin - Retrieves the appropriate builtin function for a given command
 * @cmd: command for which the builtin function is needed
 * Return: Function pointer to the builtin command, Otherwise NULL
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin_list[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};

	int i;

	/*Iterate through the builtin list to find the matching command*/
	for (i = 0; builtin_list[i].name; i++)
	{
		if (_strcmp(builtin_list[i].name, cmd) == 0)
			break;
	}

	return (builtin_list[i].f);
}
