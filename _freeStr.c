#include "main.h"

/**
 * _freePtr - functions that frees memory
 * @str: string memory to be freed
 */

void _freePtr(char **str)
{
	int i = 0;

	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}
