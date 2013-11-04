from sets import Set
import math

"""
p1 = map( lambda x: int(x), open("primes.txt").read().splitlines() )

print "we have " + str(len(p1)) + " good primes"

primes = Set()
for prime in p1:
	primes.add( prime )

p1 = None


print "done building primes"
"""

def isPrime( n ):
	if n == 2:
		return True
	if n < 2:
		return False
	if n % 2 == 0:
		return False;
#	return n in primes
	j = 3
	while j < int(math.sqrt(n)+1):
		if n % j == 0:
			return False
		j += 2
	return True


def isTrunc( n ):
	ns = str(n)
	for t in ns:
		if int(t) % 2 == 0:
			return False
	for i in xrange( 1, len(ns)):
		print  int(ns[0:i]), int(ns[i:])
		#if not isPrime( int(ns[0:i]) ):
		#	return False
		#if not isPrime( int(ns[i:]) ):
		#	return False
	return True


print isTrunc( 37975)


digits = [2,1,3,5,7,9]

def findAllForward( nums, n ):
	for digit in digits:
		nn = n * 10 + digit
		if isPrime(nn):
			nums.append(nn)
			findAllForward(nums, nn )

def findAllBackward( nums, n, p ):
	for digit in digits:
		nn = n + digit * int(math.pow(10, p ))
		if isPrime(nn):
			nums.append(nn)
			findAllBackward(nums, nn, p + 1 )
	

nums = []
nums2 = []
for digit in digits:
	if isPrime(digit):
		print digit
		print "====================="
		findAllForward( nums, digit )
		findAllBackward( nums2, digit, 1 )
print nums, nums2

trunctable = []
for num in nums:
	if num in nums2:
		trunctable.append( num )
print "found " + str(len(trunctable)) + " primes"
print sorted(trunctable)

answer = sum( trunctable )

print answer

"""
answer = 0
for i in xrange( 10, 739397 + 1 ):
	if isPrime( i ):
		if isTrunc( i ):
			print i
			answer += i

print answer
"""
