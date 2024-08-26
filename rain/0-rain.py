#!/usr/bin/python3
"""
compute the rain
"""
def rain(walls):
    if not walls:
        return 0
    count = 0
    for i in range(len(walls)):
        right = walls[i]
        left = walls[i]
        for j in range(i, -1, -1):
            if walls[j] > left:
                left = walls[j]
        for j in range(i, len(walls)):
            if walls[j] > right:
                right = walls[j]
        count += min(left, right) - walls[i]
    return count