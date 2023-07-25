#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion Sort algorithm.
 * @list: Pointer to the pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_ellement, *temp;
    
    if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_ellement = (*list)->next;

	while (current_ellement != NULL)
	{
		temp = current_ellement;
		current_ellement = current_ellement->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			print_list(*list);
		}
	}
}
