#include "hsh.h"

/**
 * _putchar - prints a char to stdout
 * @c: the char to print
 * Return: -1 for failure, 1 for success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
