#include "main.h"

/**
 * cd_shell - Change current directory based on the provided arguments
 * @datash: Data relevant
 * Return: 1 (Success)
 */
int cd_shell(data_shell *datash)
{
	char *target_dir;
	int is_home, is_home_shortcut, is_ddash;

	target_dir = datash->args[1];

	if (target_dir != NULL)
	{
		is_home = _strcmp("$HOME", target_dir);
		is_home_shortcut = _strcmp("~", target_dir);
		is_ddash = _strcmp("--", target_dir);
	}
	if (target_dir == NULL || !is_home || !is_home_shortcut || !is_ddash)
	{
		/*Change to the home directory*/
		cd_to_home(datash);
		return (1);
	}
	if (_strcmp("-", target_dir) == 0)
	{
		/*change to the previous directory*/
		cd_previous(datash);
		return (1);
	}
	if (_strcmp(".", target_dir) == 0 || _strcmp("..", target_dir) == 0)
	{
		/*Change to the current or parent directory*/
		cd_dot(datash);
		return (1);
	}
	/*Chenge to the specified directory*/
	cd_to(datash);

	return (1);
}
