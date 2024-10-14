#include "sort.h"

void TopDownMergeSort(int A[], int iBegin, int iEnd);
void InPlaceMerge(int A[], int iBegin, int iMiddle, int iEnd);

/**
 * merge_sort - Sorts an array of integers using merge sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 * This function calls the recursive TopDownMergeSort to sort the array
 * in ascending order.
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	TopDownMergeSort(array, 0, size);
}

/**
 * TopDownMergeSort - Recursively splits and merges an array.
 * @A: The array to be sorted.
 * @iBegin: The starting index of the subarray.
 * @iEnd: The ending index of the subarray.
 *
 * This function recursively divides the array into smaller subarrays
 * and merges them back in sorted order.
 */
void TopDownMergeSort(int A[], int iBegin, int iEnd)
{
	if (iEnd - iBegin <= 1)
		return;

	int iMiddle = (iEnd + iBegin) / 2;

	TopDownMergeSort(A, iBegin, iMiddle);
	TopDownMergeSort(A, iMiddle, iEnd);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&A[iBegin], iMiddle - iBegin);
	printf("[right]: ");
	print_array(&A[iMiddle], iEnd - iMiddle);
	InPlaceMerge(A, iBegin, iMiddle, iEnd);

	print_array(A + iBegin, iEnd - iBegin);
}
/**
 * InPlaceMerge - Merges two sorted halves of an array in-place.
 * @A: The array containing two sorted subarrays.
 * @iBegin: The starting index of the left subarray.
 * @iMiddle: The index where the right subarray begins.
 * @iEnd: The ending index of the right subarray.
 *
 * This function merges two sorted subarrays of A[] into one sorted
 * array without using additional memory (in-place).
 */
void InPlaceMerge(int A[], int iBegin, int iMiddle, int iEnd)
{
	int i = iBegin;
	int j = iMiddle;

	while (i < iMiddle && j < iEnd)
	{
		if (A[i] <= A[j])
		{
			i++;
		}
		else
		{
			int value = A[j];
			int index = j;

			while (index > i)
			{
				A[index] = A[index - 1];
				index--;
			}

			A[i] = value;
			i++;
			j++;
			iMiddle++;
		}
	}
}
