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


int main(int argc, char *argv[])
{
	char *line = NULL, **array = NULL;
	size_t n = 0, count = 0;
	ssize_t nRead;
	int status;

	(void)status;
	(void)argc;
	while (1)
	{
		if (isatty(0))
			printf("$ ");
		fflush(stdout);

		nRead = getline(&line, &n, stdin);
		++count;
		/* getline failure */
		if (nRead == -1 || nRead == EOF)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit(0);
		}
		line[nRead - 1] = '\0';
		if (*line == '\0')
			continue;

		array = tokenize(line, " ");
		if (array == NULL)
			continue;
		if (access(array[0], X_OK) == -1)
		{
			fprintf(stderr, "%s: %lu: %s: not found\n", argv[0], count, array[0]);
			free_command(array);
			continue;
		}
		status = execute(array);
		line = NULL;
	}
	return (0);
}

