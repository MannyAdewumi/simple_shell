#include "shell.h"

/**
  * handle_error - handles error as bash/sh
  * @argv: shell name
  * @comm: command name
  * Return: 0
  */

int handle_error(char *argv, char *comm)
{
	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, "1", 1);
	write(2, ": ", 2);
	write(2, comm, _strlen(comm));
	perror(" ");
	return (0);
}
