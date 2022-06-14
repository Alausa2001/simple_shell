#include "main.h"
/**
 * execute - execute the command
 * @cmd: command given by the user
 * @env: environment pointer
 * Return: 1
 */
char execute(char **cmd, char **env)
{
	pid_t pid;
	int status, i = 0;
	char str[] = "/bin/", *arg;

	if (strncmp("exit", cmd[0], 4) == 0)
		return (-1);
	if (strncmp("env", cmd[0], 3) == 0)
	{
		while (env[i] != NULL)
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error: unable to fork parent");
	}
	else if (pid == 0)
	{
		if (cmd[0][0] != '/')
		{
			strcat(str, cmd[0]);
			arg = str;
		}
		else
			arg = cmd[0];
		if (execve(arg, cmd, NULL) < 0)
		{
			perror("Error:cant execute command");

		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	return (1);
}
