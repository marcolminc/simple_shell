#include "hsh.h"

/**
 * hsh - the loop for the simple shell
 * Return: void
 */
void hsh(void)
{
	char *line;
	char **args;
	int status;
	size_t len;
	ssize_t read;

	status = 1;
	do {
		prompt();
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			perror("./hsh");
			fflush(stderr);
			fflush(stdout);
			status = 1;
			break;
		}
		else if (read == 1)
			continue;
		args = tokenizer(line);
		status = hsh_exec(args);
		free(args);
		free(line);
		args = NULL;
		line = NULL;
	} while (status);
}

