#include "sort.h"

void merge_subs(int *mini_array, int *sorted_array, size_t front, size_t mid,
		size_t back);
void merge_sort_foreach(int *mini_array, int *sorted_array, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subs - Sort a mini_arrayay of integers.
 * @mini_array: A mini_arrayay of an array of integers to sort.
 * @sorted_array: A sorted_arrayer to store the sorted array.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subs(int *mini_array, int *sorted_array, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(mini_array + front, mid - front);

	printf("[right]: ");
	print_array(mini_array + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		sorted_array[k] = (mini_array[i] < mini_array[j]) ? mini_array[i++] : mini_array[j++];
	for (; i < mid; i++)
		sorted_array[k++] = mini_array[i];
	for (; j < back; j++)
		sorted_array[k++] = mini_array[j];
	for (i = front, k = 0; i < back; i++)
		mini_array[i] = sorted_array[k++];

	printf("[Done]: ");
	print_array(mini_array + front, back - front);
}

/**
 * merge_sort_foreach - Implement the merge sort algorithm through recursion.
 * @mini_array: A mini_array of an array of integers to sort.
 * @sorted_array: A sorted_array buffer to store the sorted result.
 * @front:front index of the array.
 * @back: back index of the array.
 */
void merge_sort_foreach(int *mini_array, int *sorted_array, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_foreach(mini_array, sorted_array, front, mid);
		merge_sort_foreach(mini_array, sorted_array, mid, back);
		merge_subs(mini_array, sorted_array, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *sorted_array;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;

	merge_sort_foreach(array, sorted_array, 0, size);

	free(sorted_array);
}
