#include "main.h"

/**
 * nbr_spaces - counts the number of spaces
 * in the string
 * @s: string
 * Return: number of spaces
 */

unsigned int nbr_spaces(char *s)
{
	unsigned int i, cmpt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			cmpt++;
	}
	return (cmpt);
}


/**
 * _strtok - this function works as a tokenizer for our shell
 * @str - string to be tokenized
 * Return - tokenized string.
 */

char **_strtok(char *str)
{
	int i = 0;
	const char separator[] = " ";
	unsigned int spaces = nbr_spaces(str);
	char **tokens = malloc (sizeof(char *) * (spaces + 1));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "aoshell: Unable to allocate memory");
		exit(1);
	}

	token = strtok(str, separator);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
