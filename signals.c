#include "shell.h"

/**
 * sig_handler - handels the signals
 * @sig: Signal identifier
 *
 * Return: nothing
 */

void sig_handler(int sig)
{
	(void) sig;

	write(STDOUT_FILENO, "\n$ ", 12);
	fflush(stdout);
}
