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
	char **token;
	int response = 0;
	int pipe = 0;
	ssize_t read;

	(void)argc;
	(void)argv;

	do {
		buffer = malloc(bufsize);
		if (isatty(STDIN_FILENO) == 1)
		{
			pipe = 1;
			_puts("aoshell$ ");
		}
		read = getline(&buffer, &bufsize, stdin);
		if (read == EOF)
		{
			response = -1;
			free(buffer);
			_putchar('\n');
			break;
		}

		buffer[_strlen(buffer) - 1] = '\0';
		token = _strtok(buffer);
		response = execute(token, env);
		free(token);
		free(buffer);	
	} while (pipe && response != -1);

	return (0);
}
