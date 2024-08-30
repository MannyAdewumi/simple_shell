#include "shell.h"

/**
  * print_env - prints the current environment
  * @environ: environment variable
  */

void print_env(char **environ)
{
	char **s = environ;
	int i = 0;

	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}
}
