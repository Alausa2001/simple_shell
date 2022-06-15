#include "main.h"

/**
 * _freePtr - functions that frees memory
 * @str: string memory to be freed
 * Return: NULL.
 */
void _freePtr(char **str)
{
	int i = 0;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
}
