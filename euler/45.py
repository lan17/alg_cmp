def T( n ):
	return (n*(n+1))/2

def P( n ):
	return (n*(3*n-1))/2

def H( n ):
	return n*(2*n-1)

tri = []
pen = []
he = []

for i in xrange( 1000000 ):
	tri.append( T(i) )
	pen.append( P(i) )
	he.append( H(i) )

def in_list( l, n ):
	a = 0
	b = len( l ) - 1
	p1 = -1
	while( a < b ):
		p = (a + b )/2
		if p1 == p:
			break
	#	print a,b,p,l[p]
		if l[p] == n:
			return True
		if l[p] > n:
			b = p
		if l[p] < n:
			a = p
		p1 = p
	return False

print in_list( tri, 40755 )

for num in tri:
	if in_list( pen, num ) and in_list(he, num ):
		print num
