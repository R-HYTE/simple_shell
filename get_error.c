#include "main.h"

/**
 * get_error - Calls the appropriate error function based on the error value
 * @datash: Data structure containing arguments and status
 * @eval: Error value
 * Return: The error value
 */
int get_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		/*Error related to environment*/
		error = error_env(datash);
		break;
	case 126:
		/*Permission related error*/
		error = path_permission_error(datash);
		break;
	case 127:
		/*Comand not found*/
		error = error_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = error_exit_shell(datash);/*Exit error*/
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = error_get_cd(datash);/*CD realated error*/
		break;
	}

	/*Print and free the error message*/
	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;/*Set status to the error value*/
	return (eval);
}
