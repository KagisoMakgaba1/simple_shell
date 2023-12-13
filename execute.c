#include "main.h"

/**
 * execute - executes the input
 * @command: the command to be executed
 *
 * Return: the status of the child process
 */

int execute(char **command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
			perror("execve");
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	return (status);
}
