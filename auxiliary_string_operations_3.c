#include "main.h"

/**
 * rev_string - Reverses a string.
 * @str: input string to be reversed
 * Return: void
 */
void rev_string(char *str)
{
	int length, start, end;
	char temp;

	if (str == NULL)
		return;

	length = 0;
	while (str[length] != '\0')
		length++;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		/* Swap characters at start and end positions */
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		/* Move towards the center */
		start++;
		end--;
	}
}
