#include "lists.h"
#include <stdlib.h>

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
		while (current->next != NULL && current->n < number)
		{
			prev = current;
			current = current->next;
		}
		prev->next = new;
		new->next = current;
	}
	return (new);
}
