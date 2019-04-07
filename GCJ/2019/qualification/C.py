#!/usr/bin/env python3
import sys


def is_prime(x):
    for i in range(2, x // 2 + 1, 2):
        if x % i == 0:
            return False
    return True


primes = [2] + list(filter(lambda x: is_prime(x), range(3, 20000, 2)))


def solve(nums):
    # print(nums)
    first_primes = list(factor(nums[0]))
    # print(first_primes)

    for num in nums[1:]:
        last_prime = first_primes[-1]
        first_primes.append(num // last_prime)

    prime_to_char = {}
    sorted_primes = sorted(set(first_primes))
    # print(sorted_primes)
    for i, prime in enumerate(sorted_primes):
        prime_to_char[prime] = chr(ord('A') + i)
    # print(prime_to_char)

    return "".join(map(lambda x: prime_to_char[x], first_primes))


def factor(x):
    for prime in primes:
        if x % prime == 0:
            return prime, x // prime
    return x


data = sys.stdin.readlines()
T = int(data[0])

for case_num in range(0, T):
    N, L = list(map(lambda x: int(x), data[case_num * 2 + 1].split(" ")))
    solution = solve(list(map(lambda x: int(x), data[case_num * 2 + 2].split(" ")[0:L])))
    print("Case #%d: %s" % (case_num + 1, solution))
