#include "main.h"
/**
 *
 */
void execute(const char *commands)
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
		char **argv = (char **)malloc(3 * sizeof(char *));
		char *command = strdup("/bin/ls");  /* set the command */
		
		argv[0] = command;
		argv[1] = strdup("-l");
		argv[2] = strdup("/tmp");
		argv[3] = NULL;
		
		if (execve(command, argv, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}

        
		/* Free allocated memory */
        
		free(command);
        
		for (int i = 1; i <= 3; i++) {
            
			free(argv[i]);
        
		}
        free(argv);
	}
	else
	{
		wait(NULL); /* the  parents process waits when the child process is finished */
	}
}
