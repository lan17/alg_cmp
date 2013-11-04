primes = map( lambda x: int(x), open("primes.txt").read().splitlines() )

print "done building primes"

def ndiv(n):
	p_facts = {}
	while n > 1:
		#print n
		for prime in primes:
			if n % prime == 0:
				if not prime in p_facts:
					p_facts[prime] = 1
				else:
					p_facts[prime] += 1
				n /= prime
				break
	#print p_facts
	return p_facts

p = 100000
while True:
	
