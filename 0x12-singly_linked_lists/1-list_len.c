#include <stddef.h>
#include "lists.h"
/**
 * list_len - Returns the number of elements in a linked list_t list.
 * @h: Pointer to the head of the linked list.
 *
 * Return: The number of elements in the linked list.
 */
size_t list_len(const list_t *h)
{
	size_t num = 0;
	const list_t *current = h;

	while (current != NULL)
	{
		num++;
		current = current->next;
	}

	return (num);
}

