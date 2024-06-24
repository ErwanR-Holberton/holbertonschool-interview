#include "lists.h"
#include <time.h>

/**
 * check_cycle - test if list has a loop
 * @list: pointer to list to be freed
 * Return: 1 if its a loop
 */
int check_cycle(listint_t *list)
{
	listint_t *copy = list, *copy2 = NULL;
	time_t startTime = time(NULL);
	int pause = 0;

	while (copy != NULL)
	{
		copy = copy->next;
		if (copy == list || (copy == copy2 && copy2 != NULL))
			return (1);
		if (!pause && time(NULL) - 1 > startTime)
		{
			pause = 1;
			copy2 = copy;
		}
	}
	return (0);
}
