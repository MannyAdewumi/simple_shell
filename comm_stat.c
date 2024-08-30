#include "shell.h"

/**
  * comm_stat - to check if argument can be executed and set it
  * @av: array of arguments inserted
  * @path: array of path from env
  * Return: 1 if cmd can be executed, 0 otherwise
  */

int comm_stat(char **av, char **path)
{
	char *comm_path = NULL, *new_path = NULL;
	int i;

	struct stat st;

	if (path == NULL)
	{
		free(path);
		free(av);
		return (0);
	}

	for (i = 0; path[i] != NULL; i++)
	{
		comm_path = _strcat(path[i], "/");
		new_path = _strcat(comm_path, av[0]);
		if (stat(new_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			av[0] = new_path;
			free(comm_path);
			free(path[0]);
			free(path);
			return (1);
		}
		free(comm_path);
		free(new_path);
	}
	free(path[0]);
	free(path);
	return (0);
}
