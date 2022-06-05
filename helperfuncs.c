#include "main.h"

/**
 * _strlen - calculates the length of
 * string excluding the null byte '\0'
 * @str: string to be counted
 * Return: number of characters.
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}


