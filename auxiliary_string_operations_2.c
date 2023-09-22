#include "main.h"

/**
 * _strdup - duplicates a str in the heap memory.
 * @original: Type char pointer str
 * Return: duplicated string
 */
char *_strdup(const char *original)
{
	char *duplicate;
	size_t length;

	length = _strlen(original);
	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);
	_memcpy(duplicate, original, length + 1);
	return (duplicate);
}

/**
 * _strlen - Returns the lenght of a string.
 * @original: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *original)
{
	int length;

	for (length = 0; original[length] != 0; length++)
	{
	}
	return (length);
}

/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, matches = 0;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				matches++;
				break;
			}
		}
	}
	if (i == matches)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *current_position, *str_end;
	char *token_start;
	unsigned int i, found = 0;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		current_position = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	token_start = current_position;
	if (token_start == str_end) /*Reaching the end*/
		return (NULL);

	for (found = 0; *current_position; current_position++)
	{
		/*Breaking loop finding the next token*/
		if (current_position != token_start)
			if (*current_position && *(current_position - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*current_position == delim[i])
			{
				*current_position = '\0';
				if (current_position == token_start)
					token_start++;
				break;
			}
		}
		if (found == 0 && *current_position) /*Str != Delim*/
			found = 1;
	}
	if (found == 0) /*Str == Delim*/
		return (NULL);
	return (token_start);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
