#include "tsh.h"

/**
 * free_tokens - frees the tokens array
 * @tokens: the array to free
 * Return: void
 */
void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; ++i)
	{
		free(tokens[i]);
	}
	free(tokens);
}
