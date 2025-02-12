#include "sort.h"

/**
* shell_sort - sort an int array using knuth sequence
* @array: int array to sort
* @size: size of array
*
* Return: n/a
*/

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
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
				swap(&array[j], &array[j - gap]);

		}
		gap /= 3;
		print_array(array, size);
	}
}

/**
* swap - swaps values in an array at spots a and b
* @a: value in array
* @b: value in array
*
* Return: n/a
*/

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
