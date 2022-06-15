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

/**
 * _strncmp - check if two strings are similar
 * and returns its integer value
 * @str1: string variable
 * @str2: string variable
 * @n: number of bytes
 * Return: 0 or any integer variable.
 */

int _strncmp(char *str1, char *str2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str[i]);
	}

	return (0);
}
