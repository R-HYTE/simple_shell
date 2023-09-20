#include "0-main.h"
/**
 * eugo_print - function prints the provided answer to the standard output.
 *
 * @answer: Pointer to a null-terminated string containing the answer to print.
 *
 */
void eugo_print(const char *answer)
{
	write(STDOUT_FILENO, answer, strlen(answer));
}
