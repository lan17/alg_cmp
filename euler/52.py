def good(x):
	x1s = str(x)
	xt = x
	for t in xrange( 2, 7 ):
		xt = x * t
		x2s = str(xt)
		#print x2s
		if len( x1s ) != len( x2s ):
			return False
		for i in x1s:
			if not i in x2s:
				return False
	return True

i = 1
while not good(i):
	i += 1

print i
		
