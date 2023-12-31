#include "main.h"

/**
 * error_env - Generates an error message for the 'env' command
 * @datash: Data structure containing relevant information.
 * Return: The generated error message.
 */
char *error_env(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = _itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(datash->argv[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));

	if (error == NULL)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * path_permission_error - Generates an error message for permission denied on a path
 * @datash: Data structure containing relevant information
 * Return: The generated error message
 */
char *path_permission_error(data_shell *datash)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = _itoa(datash->counter);
	length = _strlen(datash->argv[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
