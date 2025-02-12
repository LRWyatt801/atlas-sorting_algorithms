#include "sort.h"

/**
* print_array - prints an array
* @array: array to print
* @size: size of array
*
* Return: n/a
*/

void print_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}
