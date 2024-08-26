
def rain(walls):
    if not walls:
        return 0
    length = len(walls)
    left = 0
    while (walls[left] == 0):
        left += 1
        if left > length:
            return 0

    right = left + 1
    while (walls[right] == 0):
        right += 1
        if right > length:
            return 0

    end = 0
    count = 0
    while (not end):
        mini = min(walls[left], walls[right])
        count += (right - left - 1) * mini

        right += 1
        if right >= length:
            return count
        while (walls[right] == 0):
            right += 1
            if right >= length:
                return count
        left += 1
        if left >= length:
            return count
        while (walls[left] == 0):
            left += 1
            if left >= length:
                return count
