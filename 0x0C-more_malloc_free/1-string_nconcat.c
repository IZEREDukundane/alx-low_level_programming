#include "main.h"

/**
 * string_nconcat - Concatenates two strings.
 * @s1: First string.
 * @s2: Second string.
 * @n: First n bytes of s2.
 *
 * Return: # A pointer to a newly allocated space in memory,
 *           which contains s1, followed by the first n bytes
 *           of s2, and null terminated.
 *         # NULL If the function fails.
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int i, charCount;
	char *str;
	unsigned int j;

	charCount = 0;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		charCount++;

	str = malloc(sizeof(char) * (charCount + n + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		str[i] = s1[i];

	for (j = 0; j < n; j++)
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}
