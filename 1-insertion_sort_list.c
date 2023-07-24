#include "sort.h"

/**
 * swap - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: poniter to the second node to swap with.
 */
void swap(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}


/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *to_insert, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = next_node)
	{
		next_node = current->next;
		to_insert = current->prev;
		while (to_insert != NULL && current->n < to_insert->n)
		{
			swap(list, &to_insert, current);
			print_list((const listint_t *)*list);
		}
	}
}
