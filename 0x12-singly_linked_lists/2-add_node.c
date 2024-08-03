#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - add new node at the brginning of a list_t list
 * @head: pointer to the pointer to the head of the list
 * @str: string to be stored in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int len = 0;

	/* allocate memory for the new node */
	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	/* duplicate the string and store it in new_node */
	new_node->str = strdup(str);

	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* calculate the length of the string */
	while (str[len] != '\0')
	{
		len++;
	}
	new_node->len = len;

	/* link the new node to the head of the list */
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
