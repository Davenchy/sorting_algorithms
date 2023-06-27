#include "sort.h"

/**
 * calculate_gap - calculates the gap using Knuth sequence
 * @size: the size of the array
 * Return: the sutable gap for an array of @size
 */
size_t calculate_gap(size_t size)
{
	size_t gap = 1, last = 1;

	for (; gap < size; last = gap, gap = gap * 3 + 1)
		;

	return (last);
}

/**
 * shell_sort - sorting an array using shellsort algorithm using Knuth sequence
 * @array: the array to sort
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || !size)
		return;

	for (gap = calculate_gap(size); gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
