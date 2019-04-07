#!/usr/bin/env python3
import sys


def has_4(x):
    while x > 0:
        if x % 10 == 4:
            return True
        x = x // 10
    return False


def solve(num):
    for x in range(0, num):
        if has_4(x):
            continue
        y = num - x
        if has_4(y):
            continue
        return x, y

def subtract_1(x):
    ret = 0
    while x > 0:
        c = x % 10
        if c == 4:
            c -= 1
        ret += c
        ret *= 10
        x = x // 10
    return ret



def solve_2(num):
    #x = subtract_1(num)
    x = int(str(num).replace("4", "3"))
    return x, num - x

input = sys.stdin.readlines()
T = int(input[0])

for case_num in range(0, T):
    solution = solve_2(int(input[case_num + 1]))
    print("Case #%d: %d %d" % (case_num + 1, solution[0], solution[1]))
