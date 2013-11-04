from sets import Set

mem = dict()

def divisors1(n,d):
#	if n in mem:
		#return d | mem[n]
	if n == 1:
		return d
	for i in xrange( 2,n/2+1):
		if n % i == 0:
			d.add(i)
			d.add(n/i)
			d |= divisors1(n/i,d)
#	mem[n] = d
	return d

def divisors(n):
	return divisors1(n,Set([1]))

def d(n):
	return sum(divisors(n))

def is_amicable(a):
	b = d(a)
	#print b
	if a == b:
		return False
	db = d(b)
	#print db
	if db == a:
		return True
	return False
ans = 0
for i in xrange(1,10000):
	if is_amicable(i):
		ans += i
print ans
