#include "sort.h"

/**
 * get_max_int - Get the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max_int(int *array, int size)
{
	int max_int, i;

	for (max_int = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_int)
			max_int = array[i];
	}

	return (max_int);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: Array of integers.
 * @size: size of the array.
 *
 * Description: Sets and Prints the counting array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max_int, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max_int = get_max_int(array, size);
	count = malloc(sizeof(int) * (max_int + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max_int + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max_int + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max_int + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
