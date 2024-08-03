#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the pointer to the head of the list
 * @str: string to be store in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *old_node;
	list_t *start_node;
	unsigned int len = 0;

	old_node = malloc(sizeof(list_t));
	if (old_node == NULL)
	{
		return (NULL);
	}
	old_node->str = strdup(str);
	if (old_node->str == NULL)
	{
		free(old_node);
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	old_node->len = len;

	old_node->next = NULL;
	if (*head == NULL)
	{
		*head = old_node;
	}
	else
	{
		start_node = *head;
		while (start_node->next != NULL)
		{
			start_node = start_node->next;
		}
		start_node->next = old_node;
	}
	return (old_node);
}
