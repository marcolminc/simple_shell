#include "tsh.h"

/**
 * read_line - gets user input strings(file), by line
 * @file: input file (text or stdinput)
 * Return: void
 */
void read_line(FILE *file)
{
	char *line, **tokens;
	size_t len;
	ssize_t read, i;
	int empty_line;

	line = NULL;
	len = 0;
	if (file != NULL)
	{
		while ((read = getline(&line, &len, file)) != -1)
		{
			empty_line = 1;
			for (i = 0; i < read; i++)
			{
				if (!isspace(line[i]))
				{
					empty_line = 0;
					break;
				}
			}
			if (empty_line)
			{
				continue;
			}

			tokens = tokenize_line(line);
			execute_tokens(tokens);
			free_tokens(tokens);
		}
	}
	else
	{
		putchar('$');
		while ((read = getline(&line, &len, stdin)) != -1)
		{
			empty_line = 1;
			for (ssize_t i = 0; i < read; i++)
			{
				if (!isspace(line[i]))
				{
					empty_line = 0;
					break;
				}
			}
			if (empty_line)
			{
				printf("Empty line. Enter text:\n");
				continue;
			}

			tokens = tokenize_line(line);
			execute_tokens(tokens);
			free_tokens(tokens);
		}
	}

	free(line);
}
