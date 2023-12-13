#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * free_command - handles deallocation of array
 * @command: array of commands to be freed
 */

void free_command(char **command)
{
	size_t n;

	for (n = 0; command[n] != NULL; n++)
	{
		free(command[n]);
		command[n] = NULL;
	}
	free(command);
}
