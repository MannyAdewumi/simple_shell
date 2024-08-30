#include "shell.h"

/**
  * check_path - function to split path into array
  * @path: path variable
  * Return: will return path as array
  */

char **check_path(char *path)
{
	char *copy_path = NULL, *tokenize = NULL;
	const char *del = ":=";
	char **path_toks = calloc(sizeof(char *), 64);
	int i = 0;

	if (path == NULL)
	{
		free(path);
		return (0);
	}

	if (path_toks == NULL)
	{
		free(path);
		perror("Allocated Memorry Error: ");
		return (NULL);
	}
	copy_path = strdup(path);
	tokenize = strtok(copy_path, del);

	while (tokenize != NULL)
	{
		path_toks[i] = tokenize;
		i++;
		tokenize = strtok(NULL, del);
	}
	return (path_toks);
}
