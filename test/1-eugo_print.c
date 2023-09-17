#include "main.h"
/**
 *
 */
void _print(const char *answer)
{
	write(STDOUT_FILENO, answer, strlen(answer));
}
