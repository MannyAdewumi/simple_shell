#include "shell.h"

/**
 * execute - function will excute command
 * @av: command array
 * @stat: status of cmd
 * @env: environment array
 * @argv: arguments to main function
 * Return: 1 or error
 */

int execute(char **av, int stat, char **env, char **argv)
{
	pid_t pidd;
	int status;

	if (av == NULL)
		return (-1);

	pidd = fork();

	if (pidd < 0)
	{
		perror("Failed to fork process: ");
		exit(1);
	}
	else if (pidd == 0)
	{
		if (execve(av[0], av, env) == -1)
		{
			handle_error(argv[0], av[0]);
			free(av);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (stat == 1)
		{
			free(av[0]);
		}
		free(av);
		waitpid(pidd, &status, WUNTRACED);
	}
	return (1);
}
