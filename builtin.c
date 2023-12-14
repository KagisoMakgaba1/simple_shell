#include "main.h"

/**
 * my_getenv - get the environment variable
 * @var: the environment variable
 *
 * Return: content of env variable
 */

char *my_getenv(char *var)
{
	int i = 0, j, status;

	while (environ[i])
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != var[j])
				status = 0;
		}
		if (status == 1)
			break;
		i++;
	}
	return (&environ[i][j] + 1);
}

/**
 * my_env - prints the environment
 */

void my_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * exit_builtin - exits the shell
 */

void exit_builtin(void)
{
	printf("Exiting shell..\n");
	exit(EXIT_SUCCESS);
}
