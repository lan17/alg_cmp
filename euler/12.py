from sets import Set
import math

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
	answer = 1
	for k,v in p_facts.items():
		answer *= v + 1
	return answer

print ndiv( 21 )

def t_num( i ):
	return (i*i-i)/2

ans = 1
for i in xrange(1, 500):
	ans *= i

i = 2
while True:
	n = ndiv(t_num(i))
	#print n
	if n > 500:
		break
	i += 1

print i
print ndiv( t_num(i) )
print t_num(i)
