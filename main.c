#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - the entry point
 * Return: an integer
 */

int main(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t nRead;

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		nRead = getline(&line, &n, stdin);
		if (nRead == -1 || nRead == EOF)
		{
			free(line);
			printf("\n");
			break;
		}

		if (n > 0 && line[n - 1] == '\n')
		{
			line[n - 1] = '\0';
			nRead--;
		}
		printf("%s\n", line);
	}

	return (0);
}
