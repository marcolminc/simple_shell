#include "tsh.h"

/**
 * main - entry point of the simple shell
 * @argc: number of supplied arguments
 * @argv: array of arguments (strings)
 * Return: execution status
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc > 1)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			perror("Error opening file");
			return (1);
		}
		read_line(file);
		fclose(file);
	}
	else
		read_line(NULL);

	return (0);
}
