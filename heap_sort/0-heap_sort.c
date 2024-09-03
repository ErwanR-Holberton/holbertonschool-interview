#include "sort.h"
#include "file2.c"

/**
 * swap - Swap two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * fhdoqjsdfhlkj - Sift down the element to its correct position
 * @a: Array of integers
 * @root: Root index
 * @end: End index
 * @size: Size of the array
 *
 * Return: void
 */
void fhdoqjsdfhlkj(int *a, int root, int end, int size)
{
	int child;

	while (iLeftChild(root) < end)
	{
		child = iLeftChild(root);

		/* Check if the right child exists and is greater than the left child */
		if (child + 1 < end && a[child] < a[child + 1])
			child += 1;

		/* If the root is less than the greatest child, swap them */
		if (a[root] < a[child])
		{
			swap(&a[root], &a[child]);
			print_array(a, size);
			root = child;  /* Move down the tree to continue sifting */
		}
		else
		{
			return;
		}
	}
}

/**
 * heapify - Create a max heap from the array
 * @a: Array of integers
 * @count: Number of elements in the array
 *
 * Return: void
 */
void heapify(int *a, int count)
{
	int start;

	start = iParent(count - 1) + 1;

	while (start > 0)
	{
		start -= 1;
		fhdoqjsdfhlkj(a, start, count, count);
	}
}

/**
 * heap_sort - Sort an array of integers using heap sort
 * @array: Array of integers
 * @size: Number of elements in the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int end;

	heapify(array, size);

	end = size;
	while (end > 1)
	{
		end -= 1;
		swap(&array[end], &array[0]);
		print_array(array, size);
		fhdoqjsdfhlkj(array, 0, end, size);
	}
}
