#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *current2;
	while (current->express != NULL)
	{
		printf("Value checked at index [%d] = [%d]\n", current->express->index, current->express->n);
		if (current->express->n < value)
			current = current->express;
		else
		{
			printf("Value found between indexes [%d] and [%lld]\n", current->index, current->express->index);
			while (current != NULL)
			{
				printf("Value checked at index [%d] = [%d]\n", current->index, current->n);
				if (current->n < value)
					current = current->next;
				else if (current->n == value)
					return current;
				else
					return NULL;
			}
			break;
		}
	}
	current2 = current;
	while (current2->next!= NULL)
		current2 = current2->next;
	printf("Value found between indexes [%d] and [%d]\n", current->index, current2->index);
	while (current != NULL)
	{
		printf("Value checked at index [%d] = [%d]\n", current->index, current->n);
		if (current->n < value)
			current = current->next;
		else if (current->n == value)
			return current;
		else
			return NULL;
	}
	return NULL;
}
