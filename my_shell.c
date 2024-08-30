#include "shell.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of pinters
 * @env: environment variable
 * Return: 0 on success
 */

int main(int argc, char **argv, char **env)
{
	char *get;
	char **input = NULL;
	char **path;
	int check_comm = 0;
	(void) argc;

	signal(SIGINT, sig_handler);

	while (1)
	{
		print_prompt();
		get = read_line();
		input = split_string(get, env);

		if ((_strcmp(input[0], "\n") != 0) &&
				(_strcmp(input[0], "env") != 0))
		{
			path = find_path(env);
			check_comm = comm_stat(input, path);
			execute(input, check_comm, env, argv);
		}
		else
		{
			free(input);
		}
		free(get);
	}
	return (EXIT_SUCCESS);
}
