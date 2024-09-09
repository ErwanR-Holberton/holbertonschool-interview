
#include "search_algos.h"

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

int advanced_binary(int *array, size_t size, int value)
{
    int res, mid;

    if (array == NULL || size == 0)
        return -1;

    if (size > 1)
        print_array(array, size);

    if (size == 1)
    {
        if (array[0] == value)
            return 0;
        else
            return -1;
    }

    mid = (size - 1) / 2;

    if (array[mid] >= value)
    {
        return advanced_binary(array, mid + 1, value);
    }
    else
    {
        res = advanced_binary(array + mid + 1, size - mid - 1, value);
        if (res == -1)
            return -1;
        return res + mid + 1;
    }
}