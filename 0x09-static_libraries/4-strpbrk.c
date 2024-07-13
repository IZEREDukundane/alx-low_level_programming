#include "main.h"

/**
 * _strbrk - Entry point
 * @s: input
 * @accept: input
 * Return: always 0 (Success)
 * if no set is matched - NULL.
 */
char *_strbrk(char *s, char *accept)
{
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
				return (s);
	}
	s++;
	}
	return ('\0');
}
