#include "main.h"

/**
 * cmp_env_name - compares environment variables names
 * @env_var: Environment variable name
 * @name: Name to compare against
 *
 * Return: 0 if are not equal. Otherwise length of the match
 */
int cmp_env_name(const char *env_var, const char *name)
{
	int i;

	for (i = 0; env_var[i] != '='; i++)
	{
		if (env_var[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - get the value of an environment variable
 * @name: Name of the environment variable
 * @_environ: environment variable array
 *
 * Return: value of the environment variable if is found.
 * NULL Otherwise
 */
char *_getenv(const char *name, char **_environ)
{
	char *env_var_ptr;
	int i, match_length;

	env_var_ptr = NULL;
	match_length = 0;

	for (i = 0; _environ[i]; i++)
	{
		match_length = cmp_env_name(_environ[i], name);
		if (match_length)
		{
			env_var_ptr = _environ[i];
			break;
		}
	}

	return (env_var_ptr + match_length);
}

/**
 * _env - Print the evironment variables
 * @datash: Data relevant.
 * Return: 1 (Success)
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
