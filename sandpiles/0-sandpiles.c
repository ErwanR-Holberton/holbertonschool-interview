#include <stdlib.h>
#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * check - Check 3x3 grid
 * @grid1: 3x3 grid
 * @collapse: 3x3 grid
 * Return: 1 if unstable
 */
int check(int grid1[3][3], int collapse[3][3])
{
	int i, j, check_return = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			collapse[i][j] = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] >= 4)
			{
				collapse[i][j] = 1;
				check_return = 1;
			}

	return (check_return);
}
/**
 * add - Adds 1 if not OOB
 * @grid1: 3x3 grid
 * @x: line
 * @y: col
 */
void add(int grid1[3][3], int x, int y)
{
	if (x >= 0 && x < 3 && y >= 0 && y < 3)
		grid1[x][y] += 1;
}
/**
 * spread - spread sand around
 * @grid1: 3x3 grid
 * @x: line
 * @y: col
 */
void spread(int grid1[3][3], int x, int y)
{
	grid1[x][y] -= 4;
	add(grid1, x - 1, y);
	add(grid1, x, y - 1);
	add(grid1, x, y + 1);
	add(grid1, x + 1, y);
}

/**
 * sandpiles_sum - spread sand around
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int collapse[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (check(grid1, collapse))
	{
		print_grid(grid1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (collapse[i][j])
					spread(grid1, i, j);
	}
}
