#include "tsh.h"

/**
 * find_executable - matches command with environment
 * @command: the command to be matched
 * Return: command path, if found in environment
 */
char *find_executable(char *command)
{
	char *executable, *path_env, **env;

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
		{
			executable = strdup(command);
			if (executable == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
			return executable;
		}
		else
		{
			printf("Error: Command '%s' not found\n", command);
			return NULL;
		}
	}
	else
	{
		path_env = NULL;
		env = environ;
		while (*env != NULL)
		{
			if (strncmp(*env, "PATH=", 5) == 0)
			{
				path_env = *env;
				break;
			}
			env++;
		}

		if (path_env == NULL)
		{
			perror("Error getting PATH environment variable");
			exit(EXIT_FAILURE);
		}

		char *path = strdup(path_env + 5);
		if (path == NULL) {
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}

		char *token = strtok(path, ":");
		while (token != NULL)
		{
			char *executable = malloc(MAX_PATH_LENGTH);
			if (executable == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
			snprintf(executable, MAX_PATH_LENGTH, "%s/%s", token, command);
			if (access(executable, X_OK) == 0)
			{
				free(path);
				return executable;
			}
			free(executable);
			token = strtok(NULL, ":");
		}

		free(path);
		return NULL;
    }
}
