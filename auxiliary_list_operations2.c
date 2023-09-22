#include "main.h"

/**
 * add_rvar_node - Adds a variable and its value at the end of a r_var list
 * @head: Head of the linked list.
 * @var_len: Length of the variable.
 * @value: Value of the variable.
 * @val_len: Length of the value.
 * Return: Address of the head.
 */
r_var *add_rvar_node(r_var **head, int var_len, char *value, int val_len)
{
	r_var *new_node, *temp;

	new_node = malloc(sizeof(r_var));
	if (new_node == NULL)
		return (NULL);

	new_node->len_var = var_len;
	new_node->val = value;
	new_node->len_val = val_len;

	new_node->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}

	return (*head);
}

/**
 * free_rvar_list - Frees a r_var list
 * @head: Head of the linked list.
 * Return: void
 */
void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}
