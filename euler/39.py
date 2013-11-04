def solutions( p ):
	ret = 0
	for a in xrange( 1, p /2 ):
		for b in xrange( 1, a+1):
			for c in xrange( 1, b+1 ):
				if a + b + c == p and a*a==b*b+c*c:
					ret = ret + 1
		#			ret.append((a,b,c))
	return ret

mp = 0
mpm = 0
for p in xrange( 1, 1001):
	print p
	t = solutions(p)
	if t > mpm:
		mpm = t
		mp = p

print mp
		
