#include "hsh.h"

/**
 * hsh_exit - custom exit command
 * Return: void
 */
int hsh_exit(void)
{
	puts("exiting...");
	exit(EXIT_SUCCESS);
}
