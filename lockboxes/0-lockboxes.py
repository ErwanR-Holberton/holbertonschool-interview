#!/usr/bin/python3
"""
solves lockboxes problem
"""

def open_box(index, boxes, opened_boxes):
    """open boxes recursively"""
    opened_boxes.append(index)
    for key in boxes[index]:
        if key not in opened_boxes:
            if open_box(key, boxes, opened_boxes):
                return True
    if len(boxes) == len(opened_boxes):
        return True
    return False


def canUnlockAll(boxes):
    """main function called used to call the other one"""
    opened_boxes = []
    if open_box(0, boxes, opened_boxes):
        return True

    return False
