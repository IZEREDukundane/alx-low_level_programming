#include "main.h"
/**
 * _strlen - Gets length of the string
 * @str: Pointer to string
 *
 * Return: Length
 */
int _strlen(char *str)
{
	if (*str == '\0')
	{
		return (0);
	}
	return (1 + _strlen(str + 1));
}
/**
 * palindromeCheck - Checks if string is palindrome
 * @str: Pointer to string
 * @a: Start index
 * @b: end of string
 *
 * Return: 1 if string is palindrome 0 otherwise
 */
int palindromeCheck(char *str, int a, int b)
{
	if (a >= b)
	{
		return (1);
	}
	else if (str[a] == str[b])
	{
		return (palindromeCheck(str, a + 1, b - 1));
	}
	else
	{
		return (0);
	}
}
/**
 * is_palindrome - Checks if string is palindrome
 * @s: string passed
 *
 * Return: 1 if palindrome and 0 otherwise
 */
int is_palindrome(char *s)
{
	int len;

	len = _strlen(s);
	return (palindromeCheck(s, 0, len - 1));
}
