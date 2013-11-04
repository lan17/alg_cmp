import math

for a in xrange( 1,1000):
	for b in xrange( 1,1000):
		c = math.sqrt(a**2 + b**2)
		if a + b + c == 1000:
			print a*b*c
