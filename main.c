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
	size_t n = 0;
	ssize_t nRead;
	int status;
	pid_t pid;

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

		if (*line == '\0')
			continue;

		array = tokenize(line, " ");
		if (array == NULL)
			continue;

		pid = fork();
		if (pid == -1)
			continue;

		if (pid == 0)
		{
			if (execve(array[0], array, environ) == -1)
			perror("execve");
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				status = WEXITSTATUS(status);
		}

		line = NULL;
	}

	return (0);
}

