#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list
 */

void free_list(list_t *head)
{
	list_t *current = head;
	list_t *next;

	while (current != NULL)
	{
		/* save the next node */
		next = current->next;

		/* free the current node's data */
		free(current->str);
		free(current);

		/* move to the next node */
		current = next;
	}
}
