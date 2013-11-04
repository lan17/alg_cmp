a = 1
b = 1

def numdig(x):
	ret = 0
	while x > 0:
		x /= 10
		ret += 1
	return ret

count = 1
while a / (10**999) == 0:
	t = b
	b += a
	a = t
	count += 1

print numdig(100)

print count

