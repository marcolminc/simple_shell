#include "hsh.h"

/**
 * path_append - appends dir to command to make command path from env
 * @args: the command and its arguments array
 * Return: void
 */
void path_append(char **args)
{
	char *temp;

	temp = NULL;
	if (strncmp(args[0], "/bin/", 5) != 0)
	{
		temp = (char *) malloc(strlen(args[0]) + 6);
		if (temp == NULL)
		{
			perror("./hsh");
			exit(1);
		}
		strcpy(temp, "/bin/");
		strcat(temp, args[0]);
		args[0] = (char *) malloc(sizeof(temp) + 1);
		if (args[0] == NULL)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		strcpy(args[0], temp);
		free(temp);
	}
	/* find path from PATH */
}
