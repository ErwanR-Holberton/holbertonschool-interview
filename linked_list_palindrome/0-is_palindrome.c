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
	int min = 0, max = -1;
	int arr[100];

	while (*head != NULL)
	{
		arr[max + 1] = (*head)->n;
		*head = (*head)->next;
		max++;
	}

	while (max > min)
	{
		if (arr[min] != arr[max])
			return (0);
		min++;
		max--;
	}
	return (1);
}
