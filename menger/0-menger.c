#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char* recursive(int level)
{
	printf("%d\n", level);
	int i, j, k, div, size = pow(3, level), s_size = size / 3;
	char *small, *big;

	if (size == 1)
	{
		small = malloc(size * size);
		small[0] = '#';
		return small;
	}
	else
		small = recursive(level - 1);

	big = malloc(size * size);
	div = s_size / 3;
	for (i = 0; i < s_size; i++)
	{
		for (j = 0; j < s_size; j++)
		{
			for (k = 0; k < 3; k++)
			{
				if (j / div == 1 && i / div == 1)
					big[i * size + j * s_size + k] = ' ';
				else
					big[i * size + j * s_size + k] = small[i * s_size + j];
			}
		}
	}
	free(small);
	return big;
}

void menger(int level)
{
	int i, j, size = pow(3, level);
	char *array;

	if (level < 0)
		return;

	array = recursive(level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			putchar(array[i * size + j]);
		putchar('\n');
	}
}
