#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sort a doubly linked list using the insertion sort
 * algorithm
 * @list: the doubly linked list to sort
 * Note: Will print the linked list on each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (!list)
		return;

	for (current = *list; current; current = current->next)
	{
begin:
		if (!current->prev || current->prev->n <= current->n)
			continue;

		if (current->next)
			current->next->prev = current->prev;
		current->prev->next = current->next;

		current->next = current->prev;
		current->prev = current->prev->prev;
		if (current->prev)
			current->prev->next = current;
		current->next->prev = current;

		if (!current->prev)
			*list = current;

		print_list(*list);
		goto begin;
	}
}
