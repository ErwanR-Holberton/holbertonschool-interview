#include "lists.h"
#include <stdio.h>

/**
 * len - gets lenght
 * @head: pointer to list
 * Return: lenght
 */
int len(listint_t **head)
{
	listint_t *current;
	int count = 0;

	current = *head;

	if (*head != NULL)
	{
		while (current != NULL)
		{
			current = current->next;
			count++;
		}
	}
	return (count);
}

/**
 * get - get a value
 * @head: pointer to list
 * @index: index
 * Return: value at index
 */
listint_t *get(listint_t *head, int index)
{
	listint_t *current;
	int count = 0;

	current = head;

	while (count < index)
	{
		if (current == NULL)
			return (NULL);
		current = current->next;
		count++;
	}
	if (current == NULL)
		return (NULL);
	return (current);
}

/**
 * is_palindrome - tell if palindrome
 * @head: pointer to list
 * Return: 1 or 0
 */
int is_palindrome(listint_t **head)
{
	int min = 0, lenght = len(head), max;
	listint_t *current = *head, *mid = get(*head, lenght / 2);

	max = lenght - 1;

	while (max > min)
	{
		if (current->n != get(mid, lenght - (lenght / 2) - 1 - min)->n)
			return 0;
		current = current->next;
		min++;
		max --;
	}
	return (1);
}
