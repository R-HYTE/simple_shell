#include "main.h"

/**
 * find_executable_path - Find the executable path of a command
 * @command: The command to find the executable path for.
 * Return: (full path) if command is found in any of the directories,
 * NULL (Otherwise)
 */
char *find_executable_path(char *command)
{
	char *path, *path_copy, *path_token, *file_path, *full_command_path;
	int dir_len, command_len;
	struct stat buffer;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);
	path_token = strtok(path_copy, ":");
	while (path_token)
	{
		dir_len = strlen(path_token);
		command_len = strlen(command);
		file_path = (char *)malloc(dir_len + command_len + 2);
		if (!file_path)
		{
			free(path_copy);
			return (NULL);
		}
		snprintf(file_path, dir_len + command_len + 2, "%s/%s", path_token, command);
		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		free(file_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	if (stat(command, &buffer) == 0)
	{
		full_command_path = strdup(command);
		if (!full_command_path)
			return (NULL);

		return (full_command_path);
	}
	return (NULL);
}
