#include "main.h"

/**
 * bring_line - Assigns the line var for get_line
 * @lineptr: Pointer to Buffer that stores the input str
 * @n: Size of the buffer
 * @buffer: str that is been called to line
 * @buffer_size: Size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t buffer_size)
{

	if (*lineptr == NULL)
	{
		if  (buffer_size > BUFSIZE)
			*n = buffer_size;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < buffer_size)
	{
		if (buffer_size > BUFSIZE)
			*n = buffer_size;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - Read inpt from stream
 * @lineptr: pointer to buffer that stores the input
 * @n: Size of lineptr
 * @stream: Stream to read from
 * Return: The number of bytes read
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char character = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == NULL)
		return (-1);
	while (character != '\n')
	{
		i = read(STDIN_FILENO, &character, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = character;
		input++;
	}
	buffer[input] = '\0';
	bring_line(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
