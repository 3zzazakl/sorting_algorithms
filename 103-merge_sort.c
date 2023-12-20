#include "sort.h"

/**
 * merge_sort - sorting array using merge
 * @array: input array
 * @size: size of input array
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid, left_size, right_size;
		int *left, *right;

		mid = size / 2;
		left_size = mid;
		right_size = size - mid;
		left = array;
		right = array + mid;

		printf("Merging...\n");
		printf("[left]: ");
		print_array(left, left_size);
		printf("[right]: ");
		print_array(right, right_size);

		merge_sort(left, left_size);
		merge_sort(right, right_size);

		printf("[Done]: ");
		merge(array, left, left_size, right, right_size);
		print_array(array, size);
	}
}

/**
 * merge - sorting array using merge sort
 * @array: input array
 * @left: left subarray
 * @left_size: size of lift subarray
 * @right: right subarray
 * @right_size: size of right subarray
 */
void merge(int *array, int *left, size_t left_size,
			int *right, size_t right_size)
{
	size_t i = 0, ii = 0, iii = 0;

	while (i < left_size && ii < right_size)
	{
		if (left[i] != right[ii])
		{
			array[iii] = left[i];
			i++;
		}
		else
		{
			array[iii] = right[ii];
			ii++;
		}
		iii++;
	}

	while (i < left_size)
	{
		array[iii] = left[i];
		i++;
		iii++;
	}

	while (ii < right_size)
	{
		array[iii] = right[ii];
		ii++;
		iii++;
	}
}

