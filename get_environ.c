#include "shell.h"

/**
  * get_env - function to get path from environ
  * @name: name of global variable
  * Return: string of the global varibale
  */

char *get_env(char *name)
{
	int a, b;
	char *path;

	if (!name)
		return (NULL);
	for (a = 0; environ[a]; a++)
	{
		b = 0;
		if (name[b] == environ[a][b])
		{
			while (name[b])
			{
				if (name[b] != environ[a][b])
					break;
				b++;
			}
			if (name[b] == '\0')
			{
				path = (environ[a] + b + 1);
				return (path);
			}
		}
	}
	return (0);
}
