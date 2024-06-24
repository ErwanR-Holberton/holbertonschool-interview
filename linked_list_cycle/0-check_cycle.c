#include "lists.h"

/**
 * check_cycle - test if list has a loop
 * @list: pointer to list to be freed
 * Return: 1 if its a loop
 */
int check_cycle(listint_t *list)
{
	listint_t *copy = list, *copy2 = list;

	while (copy != NULL)
	{
		copy = copy->next;
		copy2 = copy2->next;
		if (copy != NULL)
			copy = copy->next;
		else
			return (0);
		if (copy == copy2)
			return (1);
	}
	return (0);
}
