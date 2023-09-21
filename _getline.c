#include "get_main.h"
/**
 * my_getline - implementation of getline function.
 *
 * @lineptr: Pointer to the buffer storing the line.
 * @n: Pointer to the size of the buffer.
 * @fd: File descriptor to read from.
 * Return: Number of characters read, or -1 on error.
 */
ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
        static char buffer[BUFFER_SIZE], *p;
        static ssize_t len;
        char *line = *lineptr;
        size_t line_len = 0;

        if (len <= 0)
        {
                len = read(fd, buffer, BUFFER_SIZE);

                if (len <= 0)
                        return (len);
                p = buffer;
        }
        while (len > 0)
        {
                if (line_len >= *n)
                {
                        *n *= 2;
                        line = realloc(line, *n);
                        if (!line)
                                return (-1);
                }
                line[line_len++] = *p++;
                len--;
                if (line[line_len - 1] == '\n')
                {
                        line[line_len] = '\0';
                        *lineptr = line;
                        return (line_len);
                }
                if (len <= 0)
                {
                        len = read(fd, buffer, BUFFER_SIZE);
                        p = buffer;
                }
        }
        return (-1);
}
