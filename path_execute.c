#include "hsh.h"

/**
 * path_execute - executes command with accessible path
 * @args: the command and its arguments
 * Return: execution status
 */
int path_execute(char **args)
{
	int status, exit_status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("./hsh");
		return (0);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fflush(stdout);
			perror("./hsh");
			return (-1);
		}
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status != 0)
		{
			perror("./hsh");
			fflush(stdout);
			fflush(stderr);
			return (-1);
		}
		return (1);
	}
	perror("child abnormal termination");
	return (-1);
}

