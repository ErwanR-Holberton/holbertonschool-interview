#include "lists.h"
#include <stdio.h>

listint_t *reverse(listint_t *head) {
	listint_t *prev = NULL, *current = head, *next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

/**
 * is_palindrome - tell if palindrome
 * @head: pointer to list
 * Return: 1 or 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *prev = NULL, *end;
	int result = 1;

	while (fast != NULL)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next;
		if (fast!= NULL)
			fast = fast->next;
	}

	prev->next = NULL;
	end = reverse(slow);

	listint_t *copy_head = *head, *copy_end = end;

	while (copy_end != NULL)
	{
		if (copy_head->n != copy_end->n)
		{
			result = 0;
			break;
		}
		copy_head = copy_head->next;
		copy_end = copy_end->next;
	}

	end = reverse(end);
	prev->next = end;

	return (result);
}
