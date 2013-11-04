from sets import Set
import math

comb = Set([])

for i in xrange(2,101):
	for j in xrange( 2,101):
		comb.add( int( math.pow(i,j )) )
		comb.add( int( math.pow(j,i))	)
		
print len( comb )
