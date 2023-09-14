#include "main.h"
/**
 * execute_command - Function to read and execute a command.
 *
 * @commands: Pointer to the command to be executed.
 */
void execute_command(const char *commands)
{
	pid_t child_pid = fork(); /* creates a child process.. */

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *envp[] = {NULL};

		char **argv = (char **)malloc(2 * sizeof(char *));

		argv[0] = strdup(commands);
		argv[1] = NULL;

		if (execve(commands, argv, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL); /* the  parents process waits when the child process is finished */
	}

}
