#!/usr/bin/python3
from sys import argv
def check_this_queen(qx, qy, queens):
    for x, y in queens:
        if x == qx or y == qy or abs(qx - x) == abs(qy - y):
            return False
    return True

def recursive_place_queen(n, level, queens, last_queen=[0, -1]):
    start = last_queen[1] + 1
    for i in range(last_queen[0], n):
        for j in range(start, n):
            if check_this_queen(i, j, queens):
                queens.append([i, j])
                if (level == n):
                    print(queens)
                else:
                    recursive_place_queen(n, level + 1, queens, [i, j])
                queens.pop()
        start = 0


if len(argv) != 2:
    print("Usage: nqueens N")
try:
    n = int(argv[1])
except:
    print("N must be a number")
    exit(1)
if n < 4:
    print("N must be at least 4")
    exit(1)

recursive_place_queen(n, 1, [])
