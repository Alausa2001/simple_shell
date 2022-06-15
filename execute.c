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
	int status;
	char str[] = "/bin/", *arg;

	if (strncmp("exit", cmd[0], 4) == 0)
	{
		exit_cmd();
		return (-1);
	}
	if (strncmp("env", cmd[0], 3) == 0)
	{
		_printenv(env);
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
			printf("%s: No such file or directory\n", cmd[0]);
			_freePtr(cmd);
			exit_cmd();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
