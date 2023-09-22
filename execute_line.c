#include "main.h"

/**
 * exec_line - Executes built-in functions or external commands.
 * @datash: Data relevant to the command (arguments)
 * Return: 1 (Success)
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	/*Check if the command is a built-in*/
	builtin = get_builtin(datash->args[0]);

	/*Execute the built-in function*/
	if (builtin != NULL)
		return (builtin(datash));

	/*Execute external command*/
	return (cmd_exec(datash));
}
