#!/usr/bin/env python3
import sys

sys.setrecursionlimit(500000)


def path_to_dict(path):
    x, y = 0, 0
    d = dict()
    for c in path:
        d[(x, y)] = c
        if c == 'S':
            y += 1
        if c == 'E':
            x += 1
    return d

def dfs(n, x, y, path, verbotten):
    #print(path, x, y, n)
    if (x == n - 1) and (y == n - 1):
        return path
    if x >= n or y >= n:
        return None

    directions = "SE"
    if x < y:
        directions = "ES"

    for direction in directions:
        if verbotten.get((x, y)) == direction:
            #print("forbidden", x, y, direction)
            continue
        xx = x
        yy = y
        if direction == 'S':
            yy += 1
        else:
            xx += 1
        if xx < n and yy < n:
            path.append(direction)
            possible = dfs(n, xx, yy, path, verbotten)
            if possible:
                return possible
            del path[-1]
    return None

def solve(n, bad_path):
    return "".join(dfs(n, 0, 0, [], path_to_dict(bad_path)))


input = sys.stdin.readlines()
T = int(input[0])

for case_num in range(0, T):
    solution = solve(int(input[case_num * 2 + 1]), input[case_num * 2 + 2])
    print("Case #%d: %s" % (case_num + 1, solution))
