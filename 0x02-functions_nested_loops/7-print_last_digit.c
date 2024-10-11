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
    int last_digit = n % 10;

    if (last_digit < 0) 
{
        last_digit = -last_digit;
    }

    printf("%d", last_digit);

    return last_digit;
}
