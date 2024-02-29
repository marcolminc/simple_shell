#include "hsh.h"

/**
 * hsh_env - custom env built-in function
 * Return: status
 */
int hsh_env(void)
{
	int i;

	if (environ == NULL)
	{
		perror("env");
		return (-1);
	}
	else
		for (i = 0; environ[i] != NULL; i++)
			puts(environ[i]);
	return (0);
}
