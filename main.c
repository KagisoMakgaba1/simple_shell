#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - the entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: an integer
 */

char **token(char *str, const char *delim);

int main(int argc, char *argv[])
{
	char *line = NULL, **array = NULL;
	size_t n = 0;
	ssize_t nRead;

	(void)argc; (void)argv;
	while (1)
	{
		if (isatty(0))
			printf("$ ");
		fflush(stdout);

		nRead = getline(&line, &n, stdin);

		/* getline failure */
		if (nRead == -1 || nRead == EOF)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit(0);
		}

		/* remove newline character */
		line[nRead - 1] = '\0';

		array = tokenize(line, " ");
		if (array == NULL)
			continue;

		if (execve(array[0], array, NULL) == -1)
		{
			fprintf(stderr, "%s: not found\n", array[0]);
		}
		line = NULL;
	}

	return (0);
}
