#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**
 * add_node_end - adds a new node at the end of a circular doubly linked list
 * @list: double pointer to the head of the list
 * @str: string to store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
List *add_node_end(List **list, char *str)
{
	List *new;

	if (!list || !str)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->prev = new;
	new->next = new;

	if (*list == NULL)
	{
		*list = new;
		return (new);
	}
	else
	{
		if ((*list)->prev != NULL)
			(*list)->prev->next = new;

		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev = new;

		return (new);
	}
	return (NULL);
}

/**
 * add_node_begin - adds node at the beginning of a circular doubly linked list
 * @list: double pointer to the head of the list
 * @str: string to store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = add_node_end(list, str);
	*list = new;
	return (new);
}
