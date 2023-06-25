#include "sort.h"

void swap(int *a, int *b);
void quick_sort_recursive(int *array, size_t size, size_t low, size_t high);
size_t partition(int *array, size_t size, size_t low, size_t high);

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Note: Will print the elements of the array after each swap
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}

/**
 * quick_sort_recursive - the recursive part of the quick sort algorithm
 * @array: array to be sorted
 * @size: the size of the array
 * @low: the index of the left range
 * @high: the index of the right range
 */
void quick_sort_recursive(int *array, size_t size, size_t low, size_t high)
{
	size_t pivot;

	if (!array || low >= high)
		return;

	pivot = partition(array, size, low, high);

	quick_sort_recursive(array, size, low, pivot - 1);
	quick_sort_recursive(array, size, pivot + 1, high);
}

/**
 * partition - sort partition of an array
 * @array: array to be sorted
 * @size: the size of the array
 * @low: the index of the partition left range
 * @high: the index of the partition right range
 * Return: pivot index
 */
size_t partition(int *array, size_t size, size_t low, size_t high)
{
	int p = array[((high - low) / 2) + low];

	while (low < high)
	{
		while (array[low] < p)
			low++;

		while (array[high] > p)
			high--;

		if (low >= high)
			break;

		swap(&array[low], &array[high]);
		print_array(array, size);
	}

	return (high);
}

/**
 * swap - swaps two integers in array
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;

	if (!a || !b)
		return;

	*a = *b;
	*b = temp;
}
