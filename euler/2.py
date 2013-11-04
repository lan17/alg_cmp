#!/usr/bin/env python

a = 1
b = 2
ret = 0
while a <= 1e6*4:
	if a % 2 == 0:
		ret += a
	t = b
	b += a
	a = t
	print a,
print ret


