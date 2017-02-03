#!/usr/bin/env python

from collections import Counter

def is_prime(n):
	if n == 2:
		return True
	if n % 2 == 0:
		return False
	for i in xrange(3, n/2, 2):
		if n % i == 0:
			return False
	return True

def prime_factors(n):
	for i in xrange(2, n/2 + 1):
		if is_prime(i) and n % i == 0:
			return [i] + prime_factors(n/i)
	return [n]

print prime_factors(17)
print prime_factors(8)

def find_smallest_multiple(numbers):
	num_factors = dict()
	for i in numbers:
		factors = Counter(prime_factors(i))
		# print i, factors
		for prime in factors.keys():
			num = num_factors.get(prime, 1)
			if num < factors[prime]:
				num = factors[prime]
			num_factors[prime] = num
	ret = 1
	for prime, num in num_factors.iteritems():
		# print prime, num
		ret *= prime ** num
	return ret

print find_smallest_multiple(range(1,11))
print find_smallest_multiple(range(1,21))
print find_smallest_multiple(range(1,1001))
print find_smallest_multiple(range(1,10001))
		
		
