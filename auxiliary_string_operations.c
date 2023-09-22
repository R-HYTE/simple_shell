#include "main.h"

/**
 * _strcat - concatenate two strings
 * @destination: The destination string where the concatenation happens
 * @source: The source string to be concatenated
 * Return: Pointer to the destination string
 */
char *_strcat(char *destination, const char *source)
{
	int dest_length = 0, source_length;

	/*Find the length of the destination string*/
	while (destination[dest_length] != '\0')
		dest_length++;

	/*Append the source string to the destination string*/
	source_length = 0;
	while (source[source_length] != '\0')
	{
		destination[dest_length] = source[source_length];
		dest_length++;
		source_length++;
	}

	destination[dest_length] = '\0';
	return (destination);
}
/**
 * *_strcpy - Copies a string
 * @destination: destination string where the copy happens
 * @source: The source string to be copied
 * Return: Pointer to the destination string
 */
char *_strcpy(char *destination, char *source)
{
	size_t index;

	for (index = 0; source[index] != '\0'; index++)
	{
		destination[index] = source[index];
	}
	destination[index] = '\0';

	return (destination);
}

/**
 * _strcmp - Ccompare two strings
 * @str1: First string to be compared
 * @str2: Second string to be compared
 * Return: 0 always
 */
int _strcmp(char *str1, char *str2)
{
	int index = 0;

	while (str1[index] == str2[index] && str1[index])
		index++;

	if (str1[index] > str2[index])
		return (1);
	else if (str1[index] < str2[index])
		return (-1);
	else
		return (0);
}

/**
 * _strchr - locate a character in a string,
 * @str: string in search
 * @character: character to look for.
 * Return: the pointer to the first occurrence of the character.
 */
char *_strchr(char *str, char character)
{
	unsigned int index = 0;

	while (str[index] != '\0')
	{
		if (str[index] == character)
			return (str + index);
		index++;
	}
	if (str[index] == character)
		return (str + index);

	return (NULL);
}

/**
 * _strspn - gets the length of a prefix substring.
 * @str: string to search
 * @accepted_chars: The set of characters to count at the beginning of str
 * Return: Number of accepted charcters
 */
int _strspn(char *str, char *accepted_chars)
{
	int str_index, accepted_index, is_accepted;

	for (str_index = 0; str[str_index] != '\0'; str_index++)
	{
		is_accepted = 0;
		for (accepted_index = 0; accepted_chars[accepted_index] != '\0'; accepted_index++)
		{
			if (str[str_index] == accepted_chars[accepted_index])
			{
				is_accepted = 1;
				break;
			}
		}
		if (!is_accepted)
			break;
	}
	return (str_index);
}
