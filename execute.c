#include "main.h"

/**
 * execute - Execute a command
 * @argv: Array of strings representing the command and its arguments
 * Return: void
 */

void execute(char **argv)
{
	char *command = NULL;
	char *actual_command = NULL;
	pid_t pid;
	int status;

	if (argv)
	{
		pid = fork();

		if (pid == 0)
		{
			command = argv[0];
			actual_command = find_executable_path(command);

			if (actual_command == NULL)
			{
				fprintf(stderr, "Command '%s' not found.\n", command);
				exit(EXIT_FAILURE);
			}

			if (execve(actual_command, argv, NULL) == -1)
			{
				perror("Execution error");
				exit(EXIT_FAILURE);
			}

			free(actual_command);
		}
		else if (pid < 0)
		{
			perror("Fork error");
			exit(EXIT_FAILURE);
		}
		else
		{
			/*Parent process*/
			/*Wait for the child process to complete*/
			waitpid(pid, &status, 0);
		}
	}
}
