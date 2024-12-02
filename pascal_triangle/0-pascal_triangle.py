#!/usr/bin/python3
"""return a 2d array representing pascal triangle"""


def pascal_triangle(n):
    """return a 2d array representing pascal triangle"""
    array = []
    for i in range(n):
        array.append([1])
        for j in range(len(array[i - 1]) - 1):
            array[i].append(array[i - 1][j + 1] + array[i - 1][j])
        if (i != 0):
            array[i].append(1)
    return array
