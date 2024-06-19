#!/usr/bin/python3
"""
log parsing
"""
import sys

input_data = sys.stdin.read()
lines = input_data.splitlines()

count = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
total_size = 0

def print_stats():

    print("File size:", total_size)
    for code in sorted(status_codes.keys()):
        if status_codes[code] != 0:
            print(code, end="")
            print(":", status_codes[code])


for line in lines:

    slip = line.split(" ")
    total_size += int(slip[8])

    if int(slip[7]) in status_codes:
        status_codes[int(slip[7])] += 1

    count += 1

    if count %10 == 0:
        print_stats()

print_stats()
