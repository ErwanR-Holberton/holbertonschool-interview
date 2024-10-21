#!/usr/bin/python3
"""make change"""

def makeChange(coins, total):
    """make change"""
    if total <= 0:
        return 0
    mini = -1
    for c in coins:
        amount = total // c
        if c * amount == total:
            if mini == -1 or mini > amount:
                mini = amount
        else:
            if amount != 0:
                f = makeChange(coins, total - (c * amount))
                if f != -1:
                    if mini == -1 or mini > f:
                        mini = f + amount
    return mini
