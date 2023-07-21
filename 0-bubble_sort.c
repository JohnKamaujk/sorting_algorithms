#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the Bubble Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, k;

	for (i = 0; i < size - 1; i++)
	{
		int swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Set the swapped flag to true */
				swapped = 1;
			}
		}

		/* the array is already sorted */
		if (!swapped)
			break;

		/* Print the array after each swap */
		printf("After pass %lu: ", i + 1);
		for (k = 0; k < size; k++)
		{
			printf("%d ", array[k]);
		}
		printf("\n");
	}
}
