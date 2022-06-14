#include "main.h"
/**
 * main - contains the main block of shell
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *buffer;
	size_t bufsize = BUFSIZ;
	char **token;
	int response = 0;
	int pipe = 0;
	ssize_t read;

	if (argc >= 2)
	{
		if (execve(argv[1], argv, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
		return (0);
	}
	do {
		buffer = (char *)malloc(bufsize * sizeof(char));
		if (isatty(STDIN_FILENO) == 1)
		{
			pipe = 1;
			_puts("aoshell$ ");
		}
		read = getline(&buffer, &bufsize, stdin);
		if (read == EOF)
		{
			response = -1;
			_putchar('\n');
			break;
		}
		buffer[_strlen(buffer) - 1] = '\0';
		token = _strtok(buffer);
		response = execute(token);
		free(buffer);
	} while (pipe && response != -1);

	return (0);
}
