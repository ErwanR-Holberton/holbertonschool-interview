#!/usr/bin/env python3
import math

def minOperations(n):
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

