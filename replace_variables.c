#include "main.h"

/**
 * check_env - checks if the typed variable is an env variable
 * @h: Head of the linked list containing environment variables
 * @in: input string to be checked
 * @data: data structure for shell
 * Return: void
 */
void check_env(r_var **h, char *in, data_shell *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _strlen(_envr[row] + chr + 1);
				add_rvar_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_rvar_node(h, j, NULL, 0);
}

/**
 * check_vars - check if the typed variable is $? or $$
 * @h: head of the linked list containing special variables
 * @in: input string to be checked
 * @st: last status of the Shell
 * @data: data structure for shell
 * Return: void
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int i, lst_len, pid_len;

	lst_len = _strlen(st);
	pid_len = _strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_rvar_node(h, 2, st, lst_len), i++;
			else if (in[i + 1] == '$')
				add_rvar_node(h, 2, data->pid, pid_len), i++;
			else if (in[i + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + i, data);
		}
	}

	return (i);
}

/**
 * replaced_input - replaces special strings with correspondin values
 * @head: head of the linked list with special vars
 * @input: input string to be checked
 * @new_input: new input string (replaced)
 * @nlen: New length
 * Return: Replaced string
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *index;
	int i, j, k;

	index = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(index->len_var) && !(index->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (index->len_var && !(index->len_val))
			{
				for (k = 0; k < index->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < index->len_val; k++)
				{
					new_input[i] = index->val[k];
					i++;
				}
				j += (index->len_var);
				i--;
			}
			index = index->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * rep_var - calls functions to replace special strings
 * with their values
 * @input: Input string
 * @datash: Data structure for shell
 * Return: Replaced string
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *index;
	char *status, *new_input;
	int old_len, new_len;

	status = _itoa(datash->status);
	head = NULL;

	old_len = check_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	index = head;
	new_len = 0;

	while (index != NULL)
	{
		new_len += (index->len_val - index->len_var);
		index = index->next;
	}

	new_len += old_len;

	new_input = malloc(sizeof(char) * (new_len + 1));
	new_input[new_len] = '\0';

	new_input = replaced_input(&head, input, new_input, new_len);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}
