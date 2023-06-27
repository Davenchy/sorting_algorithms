#include "sort.h"

/**
 * swap_nodes - swaps two neighbour nodes inside doubly linked list
 * @nodeA: the left node
 * @nodeB: the right node
 * @head: the first node of the doubly linked list
 */
void swap_nodes(listint_t *nodeA, listint_t *nodeB, listint_t **head)
{
	listint_t *prev, *next;

	if (!nodeA || !nodeB)
		return;

	prev = nodeA->prev, next = nodeB->next;
	nodeA->next = next, nodeB->prev = prev;
	nodeA->prev = nodeB, nodeB->next = nodeA;
	if (next)
		next->prev = nodeA;
	if (prev)
		prev->next = nodeB;
	else
		*head = nodeB;
}

/**
 * cocktail_sort_list - sort array using the cocktail sort algorithm
 * @list: pointer to pointer of the first node of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	char swapped = 0;

	if (!list || !*list)
		return;

loop:
	/* check forward */
	for (current = *list; current && current->next; current = current->next)
	{
		if (current->n <= current->next->n)
			continue;
		swap_nodes(current, current->next, list);
		current = current->prev;
		print_list(*list);
		swapped = 1;
	}
	if (!swapped)
		return;

	/* check backward */
	swapped = 0;
	for (; current && current->prev; current = current->prev)
	{
		if (current->n >= current->prev->n)
			continue;
		swap_nodes(current->prev, current, list);
		current = current->next;
		print_list(*list);
		swapped = 1;
	}

	if (swapped)
		goto loop;
}
