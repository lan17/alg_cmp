from sets import Set

def proper_divisors( n ):
	ret = []
	for i in xrange( 1, n/2 +1):
		if n % i == 0:
			ret.append(i)
	return ret

def get_abundant( lim ):
	ret = []
	for i in xrange( 1, lim ):
		psum = reduce( lambda x,y: x + y, proper_divisors( i ), 0 )
		if psum > i:
			ret.append(i)
	return ret

def get_nums( lim, abundant ):
	bad = Set()
	for i in xrange( 0, len(abundant ) ):
		for j in xrange( i, len( abundant ) ):
			bad.add( abundant[i] + abundant[j] )
	nums = []
	for i in xrange( 1, lim ):
		if not i in bad:
			nums.append( i )
	return nums
	

abundant = get_abundant( 28124  )
print abundant[0]
print len( abundant )
nums = get_nums( 28124, abundant )
print len( nums )
print reduce( lambda x,y: x + y, nums, 0 )
