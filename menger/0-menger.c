#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char* recursive(int level)
{
	printf("%d\n", level);
	int i, j, k, l, size = pow(3, level), s_size = size / 3;
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

	for (k = 0; k < 3; k++)
	{
		for (l = 0; l < 3; l++)
		{
			for (i = 0; i < s_size; i++)
			{
				for (j = 0; j < s_size; j++)
				{
					if (k == 1 && l == 1)
						big[(k * s_size + i) * size + l * s_size + j] = ' ';
					else
						big[(k * s_size + i) * size + l * s_size + j] = small[i * s_size + j];
				}
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

	printf("test\n");
	array = recursive(level);
	printf("test2\n");

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			putchar(array[i * size + j]);
		putchar('\n');
	}
}
