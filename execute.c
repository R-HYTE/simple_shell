#include "main.h"

/**
 * execute - Execute the specified command
 * @command: The command to execute
 */
void execute(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {
		/* Child process */
		if (execlp(command, command, NULL) == -1)
		{
			fprintf(stderr, "./hsh: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		int status;
		waitpid(pid, &status, 0);
	}
}
