#include "sort.h"

/**
 * bubble_sort - sort @array using the bubble sort algorithm
 * @array: the array to sort
 * @size: the number of elements in the array
 * Note: Will print the array on each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	char swapped = 0;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++, swapped = 0)
	{
		for (j = 0; j < size - (1 + i); j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}
