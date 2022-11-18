#include "binary_trees.h"
#include <stdio.h>

/**
 * array_to_heap - A function that builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created Binary Heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t i = 0;

	if (!array || size < 1)
		return (NULL);

	heap_insert(&tree, array[0]);

	for (i = 1; i < size; i++)
		heap_insert(&tree, array[i]);

	return (tree);
}
