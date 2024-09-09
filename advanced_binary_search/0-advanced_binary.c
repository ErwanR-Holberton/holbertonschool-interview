
#include "search_algos.h"

/**
 * print_array - Prints the elements of an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * This function prints the elements of the array in a format
 * "element1, element2, ..., elementN".
 */
void print_array(int *array, size_t size)
{
    size_t i;

    printf("Searching in array: ");
    for (i = 0; i < size; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

/**
 * advanced_binary - Performs an advanced binary search on a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value in the array,
 * or -1 if the value is not present.
 *
 * This function searches for the first occurrence of a value in a sorted array
 * using the binary search algorithm. It prints the portion of the array that
 * is being searched at each step.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t L = 0;
    size_t R = size - 1;

    while (L <= R)
    {
        size_t m = L + (R - L) / 2;

        print_array(array + L, R - L + 1);

        if (array[m] < value)
            L = m + 1;
        else
        {
            R = m;
            if (array[m] == value && (m == 0 || array[m - 1] != value))
                return ((int)m);
        }
    }
    return (-1);
}
