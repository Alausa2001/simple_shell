#include "main.h"
/**
 * main - contains the main block of shell
 * @argc: no of command line args
 * @argv: array of command line args
 * @env: the environment pointer
 * Return: 0
 */
int main(int argc, char *argv[], char **env)
{
	char *buffer;
	size_t bufsize = 0;
	char **token = NULL;
	int pipe = 0;
	ssize_t read;

	(void)argc;
	(void)argv;

	do {
		if (isatty(STDIN_FILENO) == 1)
		{
			pipe = 1;
			_puts("aoshell$ ");
		}
		buffer = malloc(bufsize);
		read = getline(&buffer, &bufsize, stdin);
		if (read == EOF)
		{
			free(buffer);
			_putchar('\n');
			break;
		}

		buffer[_strlen(buffer) - 1] = '\0';
		token = _strtok(buffer);
		execute(token, env);
		_freePtr(token);
	} while (pipe);

	return (0);
}
