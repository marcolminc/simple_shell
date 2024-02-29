#include "hsh.h"

/**
 * match_built_in - matches input built-in with custom built-in commands
 * @args: the command with its arguments
 * Return: match status
 */
int match_built_in(char **args)
{
	static const Built_in built_ins[] = {
		{"exit", hsh_exit},
		{"env", hsh_env}
	};
	int i;

	for (i = 0; i < (int)(sizeof(built_ins) / sizeof(Built_in)); i++)
		if (strcmp(args[0], built_ins[i].name) == 0)
		{
			built_ins[i].function();
			return (1);
		}
	return (0);
}
