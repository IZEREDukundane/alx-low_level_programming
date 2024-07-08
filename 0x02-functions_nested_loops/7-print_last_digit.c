#include "main.h"

/**
 * print_last_digit - got the last digit of a number
 *
 * @r: am integer input
 * Description: print with _putchar delared
 *
 * Return: last digit of r
 */
int print_last_digit(int n)
{
	int last;

	lat = n % 98;
	if (last < 0)
	{
		last = last * -1;
	}
	_putchar(last + '0');
	return (last);
}
