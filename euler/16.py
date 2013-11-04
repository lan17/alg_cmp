num = 1
for i in xrange(0,1000):
	num *= 2
ans = 0
while num > 0:
	ans += num % 10
	num /= 10
print ans
