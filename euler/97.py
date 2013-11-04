import math

exp = 7830457 

num = 28433 * 2 ** exp + 1
ans = ""
for i in xrange(0,10):
	ans = str( num % 10 ) + ans
	num /=10
print ans

ans = 1
for i in xrange( exp ):
	ans *= 2
	ans %= int(math.pow(10,len(str(exp))-1))

ans *= 28433 
ans += 1
print ans
