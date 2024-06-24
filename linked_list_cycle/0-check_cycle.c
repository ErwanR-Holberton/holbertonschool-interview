#include "lists.h"

/**
 * check_cycle - test if list has a loop
 * @list: pointer to list to be freed
 * Return: 1 if its a loop
 */
int check_cycle(listint_t *list)
{
	listint_t *copy = list;

	while (copy->next != NULL)
	{
		copy = copy->next;
		if (copy == list)
			return (1);
	}
	return (0);
}
