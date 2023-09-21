#include "main.h"
/**
 * execute_command - Function to read and execute a command.
 *
 * @commands: Pointer to the command to be executed.
 */
void execute_command(const char *commands)
{
	char *command = NULL;
	char *real_command = NULL;
	int status;
        pid_t child_pid; /* creates a child process.. */

	if (argv)
	{
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			command = argv[0];
			real_command = find_executable_path(command);

			if (real_command == NULL)
			{
				fprintf(stderr, "Command '%s' not found.\n", command);
				exit(EXIT_FAILURE);
			}
			if (execve(real_command, argv, NULL) == -1)
			{
				perror("Execution error");
				exit(EXIT_FAILURE);
			}
			free(real_command);
		}
        else
        {
                wait(NULL); /* the  parents process waits when the child process is finished */
        }
}
