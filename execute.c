#include <sys/wait.h>
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
	char **envp = NULL;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: unable to fork parent");
	}
	else if (pid == 0)
	{
		if (execve(cmd[0], cmd, envp) < 0)
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
