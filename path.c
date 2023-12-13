#include "main.h"

/**
 * get_path - gets the full path of the command
 * @command: pointer to a string containing the command to get path
 */

void get_path(char **command)
{
	char *path = NULL, *token = NULL, *dir, *path_copy;
	size_t length;

	if (*command == NULL || command == NULL)
		return;

	dir = getenv("PATH");
	if (dir == NULL)
		return;

	path_copy = strdup(dir);
	if (path_copy == NULL)
		return;

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		length = strlen(token) + strlen("/") + strlen(*command) + 1;
		path = malloc(sizeof(char) * length);

		if (path == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			free(path_copy);
			return;
		}
		sprintf(path, "%s/%s", token, *command);
		if (access(path, X_OK) == 0)
		{
			free(*command);
			*command = strdup(path);
			free(path);
			free(path_copy);
			return;
		}
		free(path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
}
