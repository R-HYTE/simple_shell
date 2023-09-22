#include "myheader.h"
/**
 * str_split - Splits a string into an array.
 *
 *  @str: The input string to be split.
 *  @delim: The delimiter character used to split the string.
 *
 *  Return: An array of dynamically allocated strings.
 */
char **str_split(char *str, const char delim)
{
	int idx = 0;
	char **result;
	int count = 0;
	char *tmp = str;
	char *last_delim = NULL;
	char delim_arr[2];
        char *token = strtok(str, delim_arr);

	delim_arr[0] = delim;
        delim_arr[1] = 0;

	/* Count how many elements will be in the array */
	while (*tmp)
	{
		if (delim == *tmp)
		{
			count++;
			last_delim = tmp;
		}
		tmp++;
	}
	/* Add space for trailing token */
	count += last_delim < (str + strlen(str) - 1);

	/* Add space for terminating null string*/
	
	count ++;
	
	result = malloc(sizeof(char*) * count);
	if (result)
	{
		while (token)
		{
			*(result + idx++) = strdup(token);
			token = strtok(0, delim_arr);
		}
		*(result + idx) = 0;
	}
	return (result);
}
