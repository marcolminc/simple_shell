#include "hsh.h"

/**
 * hsh_exec - executes the command
 * @args: the command and its arguments
 * Return: execution status
 */
int hsh_exec(char **args)
{
	if (!match_built_in(args))
	{
		path_append(args);
		if (access(args[0], X_OK) == 0)
		{
			path_execute(args);
		}
		else
			puts("./hsh: command not recognized");
	}
	return (1);
}

