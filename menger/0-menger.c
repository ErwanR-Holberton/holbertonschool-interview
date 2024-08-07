#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * recursive - compute levels of sponge recursively
 * @level: level of sponge
 * Return: array representing this lvl of sponge
 */
char *recursive(int level)
{
	int i, j, k, l, size = pow(3, level), s_size = size / 3;
	char *small, *big;

	if (size == 1)
	{
		small = malloc(size * size);
		small[0] = '#';
		return (small);
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
	return (big);
}

/**
 * menger - print menger sponge
 * @level: level of sponge
 */
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
	free(array);
}
