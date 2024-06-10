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
int get(listint_t **head, int index)
{
	listint_t *current;
	int count = 0;

	current = *head;

	if (*head == NULL)
		return (-1);
	while (count < index)
	{
		if (current == NULL)
			return (-1);
		current = current->next;
		count++;
	}
	if (current == NULL)
		return (-1);
	return (current->n);
}

/**
 * is_palindrome - tell if palindrome
 * @head: pointer to list
 * Return: 1 or 0
 */
int is_palindrome(listint_t **head)
{
	int min = 0, max = len(head) - 1;

	if (max == -1)
		return (0);

	while (max > min)
	{
		if (get(head, min) != get(head, max))
			return (0);
		min++;
		max--;
	}
	return (1);
}
