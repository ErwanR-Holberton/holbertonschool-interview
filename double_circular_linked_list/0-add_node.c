#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_list2(List *list)
{
    List *tmp;

    tmp = list;
    printf("myprint %d\n", ' ');
    while (tmp)
    {
        printf("%s %d\n", tmp->str, ' ');
        printf("\t->prev: %s\n", tmp->prev ? tmp->prev->str : "NULL");
        printf("\t->next: %s\n", tmp->next ? tmp->next->str : "NULL");
        tmp = tmp->next;
        if (tmp == list)
            break;
    }
    printf("-------%d\n", ' ');
}

int mylen(List **list)
{
	List *start = *list, *temp = start;
	int length = 0;

	if (start == NULL)
		return 0;
	while (temp->next != NULL && temp->next != start)
	{
		length++;
		temp = temp->next;
	}
	return length +1;
}

List *add_node_end(List **list, char *str)
{
	List *new;

	if (!list || !str)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
		return (NULL);

	new->prev = new;
	new->next = new;

	if (*list == NULL)
	{
		*list = new;
		return (new);
	}
	else
	{
		if ((*list)->prev != NULL)
			(*list)->prev->next = new;
		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev = new;
		return (new);
	}
	return NULL;
}
List *add_node_begin(List **list, char *str)
{
	int L = mylen(list);
	if (L == 1)
	{
		printf("%d\n", L);
		print_list2(*list);
	}
	return (add_node_end(list, str));
}
