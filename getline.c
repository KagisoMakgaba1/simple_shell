#include "main.h"

/**
 * getInput - takes input from the user
 * @line: the line to be read
 *
 * Return: input from user
 */

char *getInput(char **line)
{
	size_t n = 0;
	ssize_t nRead;

	nRead = getline(line, &n, stdin);

	if (nRead == -1 || nRead == EOF)
	{
		free(*line);
		if (isatty(STDIN_FILENO))
			printf("\n");
		exit(EXIT_SUCCESS);
	}
	(*line)[nRead - 1] = '\0';

	if (strcmp(*line, "exit") == 0)
	{
		free(*line);
		if (isatty(STDIN_FILENO))
			printf("Exiting shell..\n");
		exit(EXIT_SUCCESS);
	}

	if (strcmp(*line, "env") == 0)
	{
		my_getenv(*line);
		return (NULL);
	}
	return (*line);
}
