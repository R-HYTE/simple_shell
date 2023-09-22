#include "main.h"

/**
 * cd_dot - changes to the parent directory
 * @datash: data relevant (environment).
 * Return: void
 */
void cd_dot(data_shell *datash)
{
	char current_path[PATH_MAX];
	char *dir, *copied_pwd, *token_pwd;

	getcwd(current_path, sizeof(current_path));
	copied_pwd = _strdup(current_path);
	set_env("OLDPWD", copied_pwd, datash);

	dir = datash->args[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("PWD", copied_pwd, datash);
		free(copied_pwd);
		return;
	}
	if (_strcmp("/", copied_pwd) == 0)
	{
		free(copied_pwd);
		return;
	}
	token_pwd = copied_pwd;
	rev_string(token_pwd);
	token_pwd = _strtok(token_pwd, "/");
	if (token_pwd != NULL)
	{
		token_pwd = _strtok(NULL, "\0");

		if (token_pwd != NULL)
			rev_string(token_pwd);
	}

	if (token_pwd != NULL)
	{
		chdir(token_pwd);
		set_env("PWD", token_pwd, datash);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", datash);
	}
	datash->status = 0;
	free(copied_pwd);
}

/**
 * cd_to - changes to a directory specified
 * by the user
 * @datash: data relevant (directories)
 * Return: void
 */
void cd_to(data_shell *datash)
{
	char current_path[PATH_MAX];
	char *dir, *copied_pwd, *copied_dir;

	getcwd(current_path, sizeof(current_path));

	dir = datash->args[1];
	if (chdir(dir) == -1)
	{
		get_error(datash, 2);
		return;
	}

	copied_pwd = _strdup(current_path);
	set_env("OLDPWD", copied_pwd, datash);

	copied_dir = _strdup(dir);
	set_env("PWD", copied_dir, datash);

	free(copied_pwd);
	free(copied_dir);

	datash->status = 0;

	chdir(dir);
}

/**
 * cd_previous - changes to the previous directory
 * @datash: Data relevant (environment)
 * Return: void
 */
void cd_previous(data_shell *datash)
{
	char current_path[PATH_MAX];
	char *prev_pwd, *old_pwd, *copied_pwd, *copied_oldpwd;

	getcwd(current_path, sizeof(current_path));
	copied_pwd = _strdup(current_path);

	prev_pwd = _getenv("OLDPWD", datash->_environ);

	if (prev_pwd == NULL)
		copied_oldpwd = copied_pwd;
	else
		copied_oldpwd = _strdup(prev_pwd);

	set_env("OLDPWD", copied_pwd, datash);

	if (chdir(copied_oldpwd) == -1)
		set_env("PWD", copied_pwd, datash);
	else
		set_env("PWD", copied_oldpwd, datash);

	old_pwd = _getenv("PWD", datash->_environ);

	write(STDOUT_FILENO, old_pwd, _strlen(old_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(copied_pwd);
	if (prev_pwd)
		free(copied_oldpwd);

	datash->status = 0;

	chdir(old_pwd);
}

/**
 * cd_to_home - Change to home directory
 * @datash: data relevant (environment)
 * Return: void
 */
void cd_to_home(data_shell *datash)
{
	char *current_pwd, *home_dir;
	char current_path[PATH_MAX];

	getcwd(current_path, sizeof(current_path));
	current_pwd = _strdup(current_path);

	home_dir = _getenv("HOME", datash->_environ);

	if (home_dir == NULL)
	{
		set_env("OLDPWD", current_pwd, datash);
		free(current_pwd);
		return;
	}

	if (chdir(home_dir) == -1)
	{
		get_error(datash, 2);
		free(current_pwd);
		return;
	}

	set_env("OLDPWD", current_pwd, datash);
	set_env("PWD", home_dir, datash);
	free(current_pwd);
	datash->status = 0;
}
