import math

def divide( num ):
	q = 1
	ret = []
	q *= 10
	qs = [q]
	while q < num:
		q *= 10
		ret.append(0)
	for i in xrange( 1000000000 ):
		t = int( math.floor( q / num ) )
		ret.append( t )
		#print q
		q = q % num
		q *= 10
		if q in qs:
			break
		qs.append( q )
	return ret


seq = divide(6)
print seq
print len( seq )

ansm = 0
ans = -1
for i in xrange( 2, 1000 ):
	t = len( divide( i ) )
	if t > ansm:
		ansm = t
		ans = i
print ans
		
