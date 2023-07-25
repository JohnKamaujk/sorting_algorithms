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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t skipped_zone, a, b;

	if (array == NULL || size < 2)
		return;

	for (skipped_zone = 1; skipped_zone < (size / 3);)
		skipped_zone = skipped_zone * 3 + 1;

	for (; skipped_zone >= 1; skipped_zone /= 3)
	{
		for (a = skipped_zone; a < size; a++)
		{
			b = a;
			while (b >= skipped_zone && array[b - skipped_zone] > array[b])
			{
				int_swapper(array + b, array + (b - skipped_zone));
				b -= skipped_zone;
			}
		}
		print_array(array, size);
	}
}
