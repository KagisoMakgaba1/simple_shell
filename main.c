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
	size_t count = 0;
	int status;
	(void)status;
	(void)argc;

	while (1)
	{
		if (isatty(0))
			printf("$ ");
		fflush(stdout);

		getInput(&line);
		++count;

		if (*line == '\0')
			continue;
		array = tokenize(line, " ");
		if (array == NULL)
			continue;
		if (access(array[0], X_OK) == -1)
		{
			get_path(&array[0]);
			if (array != NULL && access(array[0], X_OK) == -1)
			{
				fprintf(stderr, "%s: %lu: %s: not found\n", argv[0], count, array[0]);
				free_command(array);
				continue;
			}
		}
		status = execute(array);
		line = NULL;
	}
	return (0);
}
