#include "myheader.h"

/**
 * execute_command - Execute a command
 * @args: Array of strings representing the command and its arguments
 * Return: void
 */

void execute_command(char **args)
{
	char *cmd = NULL;
	char *actual_cmd = NULL;
	pid_t pid;
	int status;

	if (args)
	{
		pid = fork();

		if (pid == 0)
		{
			cmd = args[0];
			actual_cmd = find_command_path(cmd);

			if (actual_cmd == NULL)
			{
				fprintf(stderr, "Command '%s' not found.\n", cmd);
				exit(EXIT_FAILURE);
			}

			if (execve(actual_cmd, args, NULL) == -1)
			{
				perror("Execution error");
				exit(EXIT_FAILURE);
			}

			free(actual_cmd);
		}
		else if (pid == -1)
		{
			perror("Fork");
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process */
			/* Wait for the child process to complete */
			waitpid(pid, &status, 0);
		}
	}
}
