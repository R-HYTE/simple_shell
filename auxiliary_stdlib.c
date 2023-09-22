#include "main.h"

/**
 * get_len - Get the lenght of a number.
 * @num: The integer
 * Return: Length of a number.
 */
int get_len(int num)
{
	unsigned int num_abs;
	int length = 1;

	if (num < 0)
	{
		length++;
		num_abs = num * -1;
	}
	else
	{
		num_abs = num;
	}
	while (num_abs > 9)
	{
		length++;
		num_abs /= 10;
	}

	return (length);
}

/**
 * _itoa - Converts integer to string.
 * @num: The integer
 * Return: Resulting String.
 */
char *_itoa(int num)
{
	unsigned int num_abs;
	int length = get_len(num);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));
	if (buffer == NULL)
		return (NULL);

	buffer[length] = '\0';

	if (num < 0)
	{
		num_abs = num * -1;
		buffer[0] = '-';
	}
	else
	{
		num_abs = num;
	}

	length--;
	do
	{
		buffer[length] = (num_abs % 10) + '0';
		num_abs /= 10;
		length--;
	}
	while (num_abs > 0);
	return (buffer);
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, length = 0, result = 0, sign = 1, multiplier = 1, i;

	while (*(s + count) != '\0')
	{
		if (length > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			sign *= -1;

		if (*(s + count) >= '0' && *(s + count) <= '9')
		{
			if (length > 0)
				multiplier *= 10;
			length++;
		}
		count++;
	}

	for (i = count - length; i < count; i++)
	{
		result = result + ((*(s + i) - '0') * multiplier);
		multiplier /= 10;
	}
	return (result * sign);
}
