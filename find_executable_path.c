#include "main.h"

char *path, *path_copy, *path_token, *file_path, *full_command_path;
int directory_length, command_length;
struct stat buffer;

char *find_executable_path(char *command)
{
	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		if (path_copy == NULL)
		{
			perror("Memory allocation error");
			return NULL;
		}

		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			command_length = strlen(command);
			file_path = (char *)malloc(directory_length + command_length + 2);
			if (file_path == NULL)
			{
				perror("Memory allocation error");
				free(path_copy);
				return NULL;
			}

			snprintf(file_path, directory_length + command_length + 2, "%s/%s", path_token, command);

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return file_path;
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}

		free(path_copy);

		if (stat(command, &buffer) == 0)
		{
			full_command_path = strdup(command);
			if (full_command_path == NULL)
			{
				perror("Memory allocation error");
				return NULL;
			}
			return full_command_path;
		}

		return NULL;
	}

	return NULL;
}
