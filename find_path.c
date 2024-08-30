#include "shell.h"

/**
  * find_path - finds path inside env
  * @env : environment variable passed from main
  * Return: will return the right path of argument
  */

char **find_path(char **env)
{
	int i;
	char **comm_path;

	for (i = 0; env[i] != NULL ; i++)
	{
		if (env[i][0] == 'P' && env[i][2] == 'T')
		{
			comm_path = check_path(env[i]);
		}
	}
	return (comm_path);
}
