from sets import Set

primes = map( lambda x: int(x), open("primes.txt").read().splitlines() )

print "built primes"

def max_sum( lim ):
	lim_i = 0
	for t in xrange( len(primes) ):
		if primes[t+1] > lim:
			lim_i = t
			break
	print lim_i
	answers = 0
	answer = 0
	prime = lim_i
	while prime > 0:
		for prime_i in xrange( 0, prime ):
			t = primes[prime]
			good = False
			for prime_j in xrange( prime_i + 1, prime ):
				t -= primes[prime_j]
				if t < 0:
					break
				if t == 0:
					s = prime_j - prime_i
					if answers < s:
						answers = s;
						answer = primes[prime]
						good = True
					break
			if good:
				break
		prime -= 1
		print answer
	return answer
	
print max_sum( int(1e6) )
