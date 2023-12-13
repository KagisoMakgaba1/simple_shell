#include "main.h"

/**
 * tokenize - breaks a string into a sequence of tokens
 * @str: the string to be tokenized
 * @delim: delimiter
 *
 * Return: a pointer to the next token, or NULL
 */

char **tokenize(char *str, const char *delim)
{
	char *token, *str_copy;
	char **str_array = NULL;
	size_t num_token = 0, i;

	if (str == NULL || *str == '\0')
		return (NULL);

	str_copy = strdup(str);

	token = strtok(str_copy, delim);
	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	free(str_copy);

	if (num_token > 0)
	{
		str_array = malloc(sizeof(char *) * (num_token + 1));
		if (str_array == NULL)
			exit(EXIT_FAILURE);

		token = strtok(str, delim);
		i = 0;
		while (token != NULL)
		{
			str_array[i++] = strdup(token);
			token = strtok(NULL, delim);
		}
		str_array[i] = NULL;
	}

	return (str_array);
}
