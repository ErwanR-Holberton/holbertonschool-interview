#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
		return (NULL);

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
	return NULL;
}
List *add_node_begin(List **list, char *str)
{
	return (add_node_end(list, str));
}
