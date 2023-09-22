#include "myheader.h"
/**
 * get_path_directories - Get an array of directories from the PATH variable.
 * Return: An array of strings representing directories.
 */

char **get_path_directories()
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char **directories = NULL;
	char *path_token = strtok(path_copy, ":");
	int num_directories = 0;

	if (!path)
		return (NULL);

	if (!path_copy)
		return (NULL);

	while (path_token)
	{
		num_directories++;
		directories = realloc(directories, sizeof(char *) * num_directories);
		directories[num_directories - 1] = strdup(path_token);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	return (directories);
}

/**
 * construct_file_path - Construct a file path given a directory and command.
 * Return: A dynamically allocated string representing the file path.
 */

char *construct_file_path(const char *directory, const char *command)
{
	int dir_len = strlen(directory);
	int command_len = strlen(command);

	char *file_path = (char *)malloc(dir_len + command_len + 2);
	if (!file_path)
	{
		return (NULL);
	}

	snprintf(file_path, dir_len + command_len + 2, "%s/%s", directory, command);
	return (file_path);
}

/**
 * find_command_path - Find the executable path of a command.
 * Return: A dynamically allocated string representing the command path,
 * or NULL if not found.
 */

char *find_command_path(const char *command)
{
	char **directories = get_path_directories();
	char *file_path = NULL;
	int i;
	struct stat buffer;


	for (i = 0; directories[i] != NULL; i++)
	{
		file_path = construct_file_path(directories[i], command);
		if (stat(file_path, &buffer) == 0)
		{
			free_array(directories);
			return (file_path);
		}
		free(file_path);
	}
	free_array(directories);

	if (stat(command, &buffer) == 0)
	{
		/*If the command exists in the current directory, return a duplicate of the command.*/
		/*This ensures that the returned pointer can be safely freed by the caller.*/
		return strdup(command);
	}

	return (NULL);
}

/**
 * free_array - Free the memory allocated for an array of strings.
 */
void free_array(char **array)
{
	int i;
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}
