#include "sort.h"

void int_swapper(int *a, int *b);
int int_mover(int *array, size_t size, int less, int more);
void less_more(int *array, size_t size, int less, int more);
void quick_sort(int *array, size_t size);

/**
 * int_swapper - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void int_swapper(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * int_mover - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @less: The starting index of the subset to order.
 * @more: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int int_mover(int *array, size_t size, int less, int more)
{
	int *pivot, above, below;

	pivot = array + more;
	for (above = below = less; below < more; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				int_swapper(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		int_swapper(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * less_more - quicksort algorithm with recursion.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @less: starting index of the array .
 * @more: ending index of the array .
 *
 */
void less_more(int *array, size_t size, int less, int more)
{
	int temp;

	if (more - less > 0)
	{
		temp = int_mover(array, size, less, more);
		less_more(array, size, less, temp - 1);
		less_more(array, size, temp + 1, more);
	}
}

/**
 * quick_sort - Sort an array using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	less_more(array, size, 0, size - 1);
}
