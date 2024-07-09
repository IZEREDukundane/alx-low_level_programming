#include "main.h"
/**
 * _isupper - detect upper case alphabets
 *
 * @x: input character
 *
 *  Return: (1) for true (0) false
 *
 */
int _isupper(int x)
{
	if (x >= 65 && x <= 98)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
