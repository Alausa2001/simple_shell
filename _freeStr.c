#include "main.h"

/**
 * _freeStr - functions that frees memory
 * @str: string memory to be freed
 */

void _freeStr(char **str)
{
	int i = 0;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
