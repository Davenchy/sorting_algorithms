#include "sort.h"
#include <stdlib.h>

/**
 * max - searches array to find the maximum value
 * @array: the array to search
 * @size: the size of the array
 * Return: the maximum value inside the array
 */
int max(int *array, size_t size)
{
	int m;
	size_t i;

	if (!array)
		return (0);

	for (i = 1, m = array[0]; i < size; i++)
		if (array[i] > m)
			m = array[i];

	return (m);
}

/**
 * counting_sort - sort array using counting sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int k;
	ssize_t i;
	int *counting = NULL, *output = NULL;

	if (!array || !size)
		return;

	k = max(array, size);
	counting = calloc(k + 1, sizeof(int));
	if (!counting)
		return;
	output = malloc(size * sizeof(int));
	if (!output)
		goto end;

	for (i = 0; i < (ssize_t)size; i++)
		counting[array[i]]++;

	for (i = 1; i <= k; i++)
		counting[i] += counting[i - 1];
	print_array(counting, k + 1);

	for (i = size - 1; i >= 0; i--)
		output[--counting[array[i]]] = array[i];

end:
	if (counting)
		free(counting);
	free(output);
}
