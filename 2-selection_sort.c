#include "sort.h"

/**
 * int_swapper - swaps 2 ints.
 * @x: int at position 1.
 * @y: int at position 2.
 */
void int_swapper(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *target;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		target = array + x;
		for (y = x + 1; y < size; y++)
			target = (array[y] < *target) ? (array + y) : target;

		if ((array + x) != target)
		{
			int_swapper(array + x, target);
			print_array(array, size);
		}
	}
}
