#!/usr/bin/python3
import math
"""fuction to calculate minum operations"""


def minOperations(n):
    """fuction to calculate minum operations"""
    v = 1
    if v >= n:
        return 0
    count = 0
    paste = v
    while v < n:
        if v + paste >= n:
            return count + 1
        count += 2
        paste = v
        v *= 2

    return count
