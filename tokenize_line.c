#include "tsh.h"

/**
 * tokenize_line - tokenizes a line of input string
 * @line: the line to be tokenized
 * Return: the array of tokens
 */
char **tokenize_line(char *line)
{
	int token_count;
	char **tokens, *token;

	tokens = malloc(MAX_TOKENS * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token_count = 0;
	token = strtok(line, TOKEN_DELIMITER);

	while (token != NULL)
	{
		tokens[token_count++] = strdup(token);
		token = strtok(NULL, TOKEN_DELIMITER);
	}

	tokens[token_count] = NULL;
	return (tokens);
}
