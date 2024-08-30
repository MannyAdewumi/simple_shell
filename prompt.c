#include "shell.h"

/**
 * print_prompt - function prints prompt and waits for input
 *
 * Return: nothing
 */

void print_prompt(void)
{
	char *s = {"$ "};

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, s, _strlen(s));
	}
}
