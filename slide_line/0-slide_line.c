#include "slide_line.h"
#include <stdio.h>

/**
 * slide_line - slide a 2048 line
 *
 * @line: Pointer to the array
 * @size: Number of elements
 * @direction: indicate left or right
 * Return: 0 Fail, 1 Success
 */
int slide_line(int *line, size_t size, int direction)
{
	int start, end, increment, last;

	if (direction == SLIDE_LEFT)
		start = 0, end = size - 1, increment = 1;
	else if (direction == SLIDE_RIGHT)
		start = size - 1, end = 0, increment = -1;
	else
		return (0);

	last = start;
	for (int i = start + increment; i != end + increment; i += increment)
	{
		if (line[i] == 0)
			continue;
		if (line[last] == 0)
		{
			line[last] = line[i];
			if (i != last)
				line[i] = 0;
		}
		else if (line[last] == line[i])
		{
			line[last] *= 2;
			line[i] = 0;
			last += increment;
		}
		else
		{
			last += increment;
			if (last != i)
			{
				line[last] = line[i];
				line[i] = 0;
			}
		}
	}

	return (1);
}
