#ifndef SORT_H
#define SORT_H

#include <stdio.h>

/***** PROTOTYPES *****/

void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

/* HELPERS */

void print_array(int *array, size_t size);
void swap(int *, int *);

#endif /* SORT_H */
