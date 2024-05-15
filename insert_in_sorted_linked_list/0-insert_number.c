#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *current, *prev = NULL;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;


	if (*head == NULL)
		*head = new;
	else
	{
		while (current != NULL && current->n < number)
		{
			prev = current;
			current = current->next;
		}
		new->next = current;
		if (prev != NULL)
			prev->next = new;
		else
			*head = new;
	}
	return (new);
}
