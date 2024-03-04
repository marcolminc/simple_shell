#include "tsh.h"

/**
 * execute_tokens - executes shell command, with its args
 * @tokens: the array of tokens as a command to execute
 * Return: void
 */
void execute_tokens(char **tokens)
{
	char *command, *executable;
	pid_t pid;

	command = tokens[0];
	executable = find_executable(command);
	if (executable == NULL)
	{
		printf("Error: Command '%s' not found\n", command);
		return;
	}

	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		execve(executable, tokens, NULL);
		perror("Execve error");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

	free(executable);
}
