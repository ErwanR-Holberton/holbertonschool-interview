#!/usr/bin/python3
"""
validate utf8
"""


def validUTF8(data):
    """validate utf8"""
    boundaries = [[0, 127], [192, 223], [224, 239], [240, 247]]
    bytes_to_read = 0
    for number in data:
        first = number % 255

        if bytes_to_read == 0:
            for i in range(len(boundaries)):
                if boundaries[i][0] <= first <= boundaries[i][1]:
                    bytes_to_read = i
        else:
            bytes_to_read -= 1
            if not 128 <= first <= 191:
                return False

    return True
