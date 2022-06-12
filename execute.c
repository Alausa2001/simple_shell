#include "main.h"
/**
 * execute - execute the command
 * @cmd: command given by the user
 * Return: 1
 */
int execute(char **cmd)
{
	pid_t pid, wpid;
	int status;
	char **envp = environ;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: unable to fork parent");
	}
	else if (pid == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
		{
			perror("Error:cant execute command");

		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		return (1);
	}
}
