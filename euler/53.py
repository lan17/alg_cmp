import math

def factorial( n ):
	ret = 1
	for i in xrange( 2, n + 1 ):
		ret *= i
	return ret

def nCr( n, r ):
	return factorial(n) / (factorial(r)*factorial(n-r))

answer = 0

for n in xrange( 1, 101 ):
	for r in xrange( 1, n ):
		p = nCr( n, r )
		if p > 1000000:
			answer += 1

print answer
