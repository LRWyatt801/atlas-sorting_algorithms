#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* counting_sort - sorts and array of int using count method
* @array: array to be sorted
* @size: size of array
*
* Return: n/a
*/

void counting_sort(int *array, size_t size)
{
	int *countArray, *outputArray;
	size_t i, max = 0;

	if (!array || size == 1)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max)
			max = (size_t)array[i];
	}

	countArray = calloc(max + 1, sizeof(int));
	outputArray = calloc(size, sizeof(int));
	if (!countArray || !outputArray)
		perror("calloc");

	/* map input array into countArray */
	for (i = 0; i < size; i++)
		countArray[array[i]]++;

	for (i = 1; i <= max; i++)
        countArray[i] += countArray[i - 1];
	print_array(countArray, max + 1);
	
	for (i = (int)size - 1; (int)i >= 0; i--)
	{
		outputArray[countArray[array[i]] - 1] = array[i];
		countArray[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = outputArray[i];

	free(countArray);
	free(outputArray);
}
