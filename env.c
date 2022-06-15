#include "main.h"

/**
 * _printenv - prints the environment
 * variable
 * @env: environment
 */

void _printenv(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
