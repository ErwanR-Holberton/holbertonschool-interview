#!/usr/bin/python3
"""
validate utf8
"""

def validUTF8(data):
    """validate utf8"""
    boundaries = [[0, 127], [192, 223], [224, 239], [240, 247]]
    for number in data:
        bytes = [(number // (2**24)) % 255, (number // (2**16)) % 255, (number // (2**8)) % 255, number % 255]
        while len(bytes) > 1 and bytes[0] == 0:
            bytes.pop(0)

        length = len(bytes)
        if length > 4:
            return False

        first = bytes.pop(0)
        if boundaries[length - 1][0] > first or first > boundaries[length - 1][1]:
            return False
        if length == 1:
            continue
        if not all(128 <= num <= 191 for num in bytes):
            return False

    return True
