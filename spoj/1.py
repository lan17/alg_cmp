import sys

lines = sys.stdin.readlines()
for line in lines:
    line = line.strip()
    if line == "42":
        break
    print line