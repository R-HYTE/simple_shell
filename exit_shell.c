#include "main.h"

/**
 * exit_shell - Handles the 'exit' command to exit the shell
 * @datash: Data relevant to the command (status and args).
 * Return: 0 (Success)
 */
int exit_shell(data_shell *datash)
{
	unsigned int exit_status;
	int is_digit;
	int arg_len;
	int is_big_number;

	if (datash->args[1] != NULL)
	{
		/*Convert argument to unsigned integer*/
		exit_status = _atoi(datash->args[1]);
		/*Check if argument is valid digit*/
		is_digit = _isdigit(datash->args[1]);
		/*Get length of argrument*/
		arg_len = _strlen(datash->args[1]);
		is_big_number = exit_status > (unsigned int)INT_MAX;
		if (!is_digit || arg_len > 10 || is_big_number)
		{
			/*Invalid argument, set error status and display error*/
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		/*set the exit to the last 8bits of the argument*/
		datash->status = (exit_status % 256);
	}
	return (0);
}
