#include "sort.h"

void swap_ahead(listint_t **list, listint_t **tail, listint_t **target);
void swap_reverse(listint_t **list, listint_t **tail, listint_t **target);
void cocktail_sort_list(listint_t **list);

/**
 * swap_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @target: A pointer to the current swapping node.
 */

void swap_ahead(listint_t **list, listint_t **tail, listint_t **target)
{
	listint_t *tmp = (*target)->next;

	if ((*target)->prev != NULL)
		(*target)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*target)->prev;
	(*target)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *target;
	else
		*tail = *target;
	(*target)->prev = tmp;
	tmp->next = *target;
	*target = tmp;
}

/**
 * swap_reverse - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @target: A pointer to the current swapping node .
 */

void swap_reverse(listint_t **list, listint_t **tail, listint_t **target)
{
	listint_t *tmp = (*target)->prev;

	if ((*target)->next != NULL)
		(*target)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*target)->next;
	(*target)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *target;
	else
		*list = *target;
	(*target)->next = tmp;
	tmp->prev = *target;
	*target = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail target algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *target;
	int tested = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (tested == 0)
	{
		tested = 1;
		for (target = *list; target != tail; target = target->next)
		{
			if (target->n > target->next->n)
			{
				swap_ahead(list, &tail, &target);
				print_list((const listint_t *)*list);
				tested = 0;
			}
		}
		for (target = target->prev; target != *list;
				target = target->prev)
		{
			if (target->n < target->prev->n)
			{
				swap_reverse(list, &tail, &target);
				print_list((const listint_t *)*list);
				tested = 0;
			}
		}
	}
}
