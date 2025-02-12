#include "sort.h"

static void merge_recursive(int *array, int left, int right);
static void merge(int *array, int left, int mid, int right);

/**
* merge_sort - sorts an array using merge sort method
* @array: array to be sorted
* @size: size of array
*
* Return: n/a
*/

void merge_sort(int *array, size_t size)
{
	if (!array)
		return;
	merge_recursive(array, 0, size - 1);
}

/**
 * merge - merges subarrays
 * @array: subarray to sort
 * @left: left index
 * @mid: mid index
 * @right: right index
 *
 * Return: n/a
 */

static void merge(int *array, int left, int mid, int right)
{
	int i, j, k;
	int sizel = mid - left + 1;
	int sizer = right - mid;

	int L[sizel], R[sizer];

	/* copy data to tmp arrays L[] and R[] */
	for (i = 0; i < sizel; i++)
		L[i] = array[left + i];
	for (j = 0; j < sizer; j++)
		R[j] = array[mid + 1 + j];

	/* print left and right merging arrays */
	printf("Merging...\n");
	printf("[left]: ");
	print_array(L, sizel);
	printf("[right]: ");
	print_array(R, sizer);

	/* merge arrays L[] and R[] sorted into array[left...right] */
	i = 0;
	j = 0;
	k = left;
	while (i < sizel && j < sizer)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	/* print sorted subarray */
	printf("[Done]: ");
	print_array(&array[left], right - left + 1);
}

/**
* merge_recursive - recursively merge sorts array
* @array: subarray to sort
* @left: left index
* @right: right index
*
* Return: n/a
*/

static void merge_recursive(int *array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		merge_recursive(array, left, mid);
		merge_recursive(array, mid + 1, right);

		merge(array, left, mid, right);
	}
}

