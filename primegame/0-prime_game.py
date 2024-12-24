#!/usr/bin/python3
""" finds winner of game"""


def isWinner(x, nums):
    """ finds winner of game"""
    if x <= 0:
        return None
    ben = sum(how_many_primes(n) % 2 == 0 for n in nums)
    return None if ben == x - ben else ("Maria" if ben < x - ben else "Ben")


def how_many_primes(n):
    """ finds number of primes"""
    precomputed_primes = precompute_primes()
    for i in range(1229):
        if precomputed_primes[i] > n:
            return i
    return 1229


def precompute_primes():
    primes = []
    for i in range(10000):
        if is_prime(i):
            primes.append(i)
    return primes


def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:  # 2 and 3 are prime numbers
        return True
    if n % 2 == 0 or n % 3 == 0:  # Eliminate multiples of 2 and 3
        return False
    i = 5
    while i * i <= n:  # Check divisors from 5 to sqrt(n)
        if n % i == 0 or n % (i + 2) == 0:  # Check i and i + 2
            return False
        i += 6  # Increment by 6 (skip multiples of 2 and 3)
    return True
