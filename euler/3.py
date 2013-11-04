#!/usr/bin/env python

import math
from sets import Set

primez=Set([])
largest_prime=3

def is_prime(x):
	global largest_prime
	if x in primez:
		return 1
	if x < largest_prime:
		return 0
	i = 2
	while i < math.sqrt(x):
		if x % i == 0:
			return 0
		i += 1
	primez.add(x)
	largest_prime = max( largest_prime, x )
	return 1

num = 600851475143
p = 3
while p < num:
	t = 0
	while num > 1:
		for i in xrange( 2, math.sqrt(num)):
			while num % i == 0:
				num /= i
				print num 
				if is_prime(i) == 1:
					p = max( p, i )
	
print p



print p
