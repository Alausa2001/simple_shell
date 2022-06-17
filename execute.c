#include "main.h"
/**
 * execute - execute the command
 * @cmd: command given by the user
 * @env: environment pointer
 * @buffer: string to be freed
 * Return: 1
 */
void execute(char *buffer, char **cmd, char **env)
{
	pid_t pid;
	int status;
	char str[] = "/bin/", *arg;

	if (strncmp("exit", cmd[0], 4) == 0)
	{
		free(cmd);
		free(buffer);
		exit_cmd();
	}
	if (strncmp("env", cmd[0], 3) == 0)
	{
		_printenv(env);
		free(buffer);
		free(cmd);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("./hsh");
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
			perror("./hsh");
			free(buffer);
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
