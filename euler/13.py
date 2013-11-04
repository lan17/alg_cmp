import os

numbers = open("20_in.txt").read().splitlines()

ans = 0
for i in numbers:
	print i
	ans += int(i)

print ans
