#include "search.h"

/**
 * search - search one by one
 *
 * @list: list of nodes
 * @index2: value for the print
 * @value: value to search
 *
 * Return: null or node with the value
 */
skiplist_t *search(skiplist_t *list, int index2, int value)
{
	skiplist_t *current = list;

	printf("Value found between indexes [%zu] and [%d]\n",
											current->index, index2);
	while (current != NULL)
	{
		printf("Value checked at index [%zu] = [%d]\n",
												current->index, current->n);
		if (current->n < value)
			current = current->next;
		else if (current->n == value)
			return (current);
		else
			return (NULL);
	}
	return (NULL);
}

/**
 * linear_skip - use linear skip method to search
 *
 * @list: list of nodes
 * @value: value to search
 *
 * Return: null or node with the value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *current2;

	if (list == NULL)
		return (NULL);
	while (current->express != NULL)
	{
		printf("Value checked at index [%zu] = [%d]\n",
				current->express->index, current->express->n);
		if (current->express->n < value)
			current = current->express;
		else
			return (search(current, current->express->n, value));
	}
	current2 = current;
	while (current2->next != NULL)
		current2 = current2->next;
	return (search(current, current2->n, value));
}
