#include "main.h"

/**
 * swap_char - swaps | and & for non-printed chars
 * @input: input string
 * @swap_to_nonprint: flag to determine whether to swap to non-printable
 * Return: swapped string
 */
char *swap_char(char *input, int swap_to_nonprint)
{
	int i;

	if (swap_to_nonprint)
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}

			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	return (input);
}

/**
 * add_nodes - tokenize the input and add separators and
 * command lines in the lists
 * @sep_head_s: head of separator list
 * @line_head: head of command lines list
 * @input: input string
 * Return: void
 */
void add_nodes(sep_list **sep_head, line_list **line_head, char *input)
{
	int i;
	char *line;

	input = swap_char(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			add_sep_node_end(sep_head, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			add_sep_node_end(sep_head, input[i]);
			i++;
		}
	}

	line = _strtok(input, ";|&");
	do {
		line = swap_char(line, 1);
		add_line_node_end(line_head, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);

}

/**
 * to_next - move to the next command line stored
 * @sep_list_ptr: pointer to the separator list
 * @line_list_ptr: pointer to the command line list
 * @datash: data structure
 * Return: void
 */
void to_next(sep_list **sep_list_ptr, line_list **line_list_ptr, data_shell *datash)
{
	int loop_sep;
	sep_list *sep_ls_curr;
	line_list *line_ls_curr;

	loop_sep = 1;
	sep_ls_curr = *sep_list_ptr;
	line_ls_curr = *line_list_ptr;

	while (sep_ls_curr != NULL && loop_sep)
	{
		if (datash->status == 0)
		{
			if (sep_ls_curr->separator == '&' || sep_ls_curr->separator == ';')
				loop_sep = 0;
			if (sep_ls_curr->separator == '|')
				line_ls_curr = line_ls_curr->next, sep_ls_curr = sep_ls_curr->next;
		}
		else
		{
			if (sep_ls_curr->separator == '|' || sep_ls_curr->separator == ';')
				loop_sep = 0;
			if (sep_ls_curr->separator == '&')
				line_ls_curr = line_ls_curr->next, sep_ls_curr = sep_ls_curr->next;
		}
		if (sep_ls_curr != NULL && !loop_sep)
			sep_ls_curr = sep_ls_curr->next;
	}

	*sep_list_ptr = sep_ls_curr;
	*line_list_ptr = line_ls_curr;
}

/**
 * split_commands - split command lines according to
 * the separators ;, | and &, and executes them
 * @datash: data structure
 * @input: input string
 * Return: 0 (exit), 1 (continue)
 */
int split_commands(data_shell *datash, char *input)
{

	sep_list *sep_head, *sep_ls_curr;
	line_list *line_head, *line_ls_curr;
	int loop;

	sep_head = NULL;
	line_head = NULL;

	add_nodes(&sep_head, &line_head, input);

	sep_ls_curr = sep_head;
	line_ls_curr = line_head;

	while (line_ls_curr != NULL)
	{
		datash->input = line_ls_curr->line;
		datash->args = split_line(datash->input);
		loop = exec_line(datash);
		free(datash->args);

		if (loop == 0)
			break;

		to_next(&sep_ls_curr, &line_ls_curr, datash);

		if (line_ls_curr != NULL)
			line_ls_curr = line_ls_curr->next;
	}

	free_sep_list(&sep_head);
	free_line_list(&line_head);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line - tokenizes the input string
 * @input: input string.
 * Return: string splitted.
 */
char **split_line(char *input)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
