#include "shell.h"

/**
  * read_line - function to readline from stdin
  * Return: will return string from stdin
  */

char *read_line(void)
{
	ssize_t get;
	char *buf = NULL;
	size_t t = 0;
	int i;

	get = getline(&buf, &t, stdin);
	if (!buf)
	{
		perror("memory error");
		return (0);
	}
	if (get == 1)
	{
		free(buf);
		return (NULL);
	}
	else if (get == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buf);
		exit(0);
	}
	else
	{
		for (i = 0; buf[i] == ' ' && buf[i + 1] == ' '; i++)
			;

		if (!buf[i] && buf[i + 1] == '\n')
		{
			free(buf);
			return (0);
		}
	}
	return (buf);
}
