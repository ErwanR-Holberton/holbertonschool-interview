#!/usr/bin/python3

def open_box(index, boxes, opened_boxes):
    opened_boxes.append(index)
    for key in boxes[index]:
        if key not in opened_boxes:
            if open_box(key, boxes, opened_boxes):
                return True
    if len(boxes) == len(opened_boxes):
        return True
    return False


def canUnlockAll(boxes):
    opened_boxes = []
    if open_box(0, boxes, opened_boxes):
        return True

    return False
