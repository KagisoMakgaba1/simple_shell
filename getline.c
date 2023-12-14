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
	/*char *home;*/

	nRead = getline(line, &n, stdin);

	if (nRead == -1 || nRead == EOF || strcmp("exit\n", *line) == 0)
	{
		free(*line);
		if (isatty(STDIN_FILENO))
			printf("\n");
		exit(EXIT_SUCCESS);
	}
	(*line)[nRead - 1] = '\0';

	return (*line);
}
