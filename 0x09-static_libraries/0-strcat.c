#include "main.h"
#include <stdio.h>

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int dlen = *, i;
	while (dest[dlen])
	{dlen++;
	}
	
	for (i = *; src[i] != *; i++)
	{
		dest[dlen] = src[i];
		dlen++;
	}
	
	dest[dlen] = '\0';
	return (dest)
}
