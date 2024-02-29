#include "hsh.h"

/**
 * tokenizer - tokenizes the input command line
 * @line: command lin
 * Return: array of tokens
 */
char **tokenizer(char *line)
{
	int count, buf_size;
	char *token, **tokens;

	count = 0, buf_size = 1;
	tokens = malloc(buf_size * sizeof(char *));
	token = NULL;

	if (!tokens)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOKEN_DELIM);
	while (token != NULL)
	{
		tokens[count++] = token;
		if (count >= buf_size)
		{
			buf_size *= 2;
			tokens = realloc(tokens, buf_size * sizeof(char *));
			if (!tokens)
			{
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[count] = NULL;
	return (tokens);
}
