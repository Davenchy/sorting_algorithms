#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Note: Will print the array elements after each swap
 */
void selection_sort(int *array, size_t size)
{
	size_t i, curr, sel;

	if (!array)
		return;

	for (curr = 0, sel = curr; curr < size - 1; sel = ++curr)
	{
		for (i = curr + 1; i < size; i++)
		{
			if (array[i] < array[sel])
				sel = i;
		}

		if (sel == curr)
			continue;
		array[curr] ^= array[sel], array[sel] ^= array[curr];
		array[curr] ^= array[sel];
		print_array(array, size);
	}
}
