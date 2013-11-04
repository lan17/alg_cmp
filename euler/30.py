def good( num ):
	s = 0
	numi = int( num )
	for i in num:
		i1 = int(i)
		s += i1*i1*i1*i1*i1
		if s > numi:
			return False
	if s == numi:
		return True
	return False

def get_nums( ):
	ret = []
	for i in xrange( 2, 999999 ):
		if good( str(i) ):
			ret.append(i)
	return ret

nums = get_nums()
print nums
print reduce( lambda x,y: x + y, nums, 0 )
