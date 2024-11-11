#!/usr/bin/python3
"""find perimeter of island"""


def safe_get_2d(array, row, col, default=0):
    """get 1 if water 0 for land ignore out of bounds"""
    try:
        return 1 - array[row][col]
    except IndexError:
        return default

def island_perimeter(grid):
    """find perimeter of island"""
    perimeter = 0
    for x in range(len(grid)):
        for y in range(len(grid[0])):
            if grid[x][y]:
                perimeter += safe_get_2d(grid, x + 1, y)
                perimeter += safe_get_2d(grid, x - 1, y)
                perimeter += safe_get_2d(grid, x, y + 1)
                perimeter += safe_get_2d(grid, x, y - 1)
    return perimeter
