#!/usr/bin/python3
"""
solves lockboxes problem
"""


def canUnlockAll(boxes):
    """main function called used to call the other one"""
    opened_boxes = []
    keys = [0]

    while len(keys) > 0:
        if keys[0] not in opened_boxes and keys[0] < len(boxes):
            opened_boxes.append(keys[0])
            for key_in_box in boxes[keys[0]]:
                if key_in_box not in opened_boxes and key_in_box not in keys:
                    if key_in_box < len(boxes):
                        keys.append(key_in_box)

        del keys[0]

    if len(boxes) == len(opened_boxes):
        return True

    return False
