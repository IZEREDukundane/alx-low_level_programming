#include "main.h"

/**
 * malloc_checked - Allocates memory using malloc.
 * @b: Target size to be allocated in bytes.
 *
 * Return: # A pointer to the allocated memory on Suceess.
 *         # exit status 98 on Failure.
 */

void *malloc_checked(unsigned int b)
{
	void *mem = malloc(b);

	if (mem == NULL)
		exit(98);
	return (mem);
}
