#include "main.h"

/**
 * _puts - prints a string to stdout
 * _putchar: integers
 * @str: pointer to the string to print
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(char *str(i));
	}
	_putchar('\n');
}
