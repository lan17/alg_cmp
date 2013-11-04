def dig_sum(n):
	ans = 0
	while n > 0:
		ans += n % 10
		n /= 10
	return ans

ans = 0

for a in xrange( 1,100):
	for b in xrange( 1, 100):
		t = dig_sum( a**b )
		ans = max( ans, t )
print ans
		
