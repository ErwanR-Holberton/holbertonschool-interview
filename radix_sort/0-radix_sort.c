#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * countDigits - Counts the number of digits in an integer
 * @n: The integer to count digits of
 *
 * Return: The number of digits in the integer
 */
int countDigits(int n)
{
	int i = 1, count = 1;

	if (n == 0)
		return (1); /* Special case: 0 has 1 digit */
	while (n / i >= 10)
	{
		i = i * 10;
		count++;
	}
	return (count);
}

/**
 * bucketize - Sorts array elements by a specific digit place
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Current digit position to sort by
 */
void bucketize(int *array, int size, int exp)
{
	int *output, count[10], i, digit;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Initialize count array */
	for (i = 0; i < 10; i++)
		count[i] = 0;

	/* Store count of occurrences of each digit */
	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}

	/* Change count[i] so that it now contains actual position */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; i >= 0; i--)
	{
		digit = (array[i] / exp) % 10;
		output[count[digit] - 1] = array[i];
		count[digit]--;
	}

	/* Copy the sorted elements into the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers using radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, i, exp = 1;

	if (!array || size <= 1)
		return;

	/* Find the maximum number to know the number of digits */
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Apply counting sort to sort elements based on each digit */
	for (i = 0; i < countDigits(max); i++, exp *= 10)
		bucketize(array, (int)size, exp);
}
