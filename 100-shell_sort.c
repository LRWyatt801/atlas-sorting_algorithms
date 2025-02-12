#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;

	if (array == NULL || size == 0)
		return;

	while (gap < size)
		gap = (gap * 3) + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for ( j = i; j >= gap && array[j] < array[j-gap]; j -= gap)
				swap(&array[j], &array[j-gap]);
		}
		print_array(array, size);
		gap /= 3;
	}
}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
