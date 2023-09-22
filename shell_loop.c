#include "main.h"

/**
 * remove_comment - removes comments from the input string
 * @in: input string
 * Return: input string without comments
 */
char *remove_comment(char *in)
{
	int i, last_valid_index;

	last_valid_index = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				last_valid_index = i;
		}
	}

	if (last_valid_index != 0)
	{
		in = _realloc(in, i, last_valid_index + 1);
		in[last_valid_index] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Main Loop of the shell
 * @datash: data relevant (av, input, args)
 * Return: void
 */
void shell_loop(data_shell *datash)
{
	int loop, eof_flag;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "($) ", 4);
		input = read_user_input(&eof_flag);
		if (eof_flag != -1)
		{
			input = remove_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			loop = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
