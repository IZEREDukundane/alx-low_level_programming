#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: The string to print
 * Retern: void
 */
void puts_half(char *str)
{
	int j = 0;
	int k;

	while (str[j] != '\0')
	{
		j++;
	}
	if (j % 2 == 1)
	{
		k = (j - 1) / 2;
		k += 1;
	}
	for (; k < j; k++)
	{
		_putchar(str[k]);
	}
	_putchar('\n');
}
