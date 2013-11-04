from sets import Set

def pan_dig( a,b,c ):
	a1 = str(a)
	b1 = str(b)
	c1 = str(c)
	n = a1 + b1 + c1
	if len(a1) + len(b1) + len(c1) != 9:
		return False
	t = 1
	while t <= 9:
		if not str(t) in n:
			return False
		t += 1
	return True

prods = Set()

for a in xrange( 1, 10000 ):
	for b in xrange( 1, a/2 ):
		t = a * b
		if pan_dig(a,b,t):
			prods.add( t )
			print a,b,t

print 7254 in prods
print prods
print sum(prods)
