powtable=[0,1,4,9,16,25,36,49,64,81]

def square(i):
	return powtable[i]

def pow(i,n):
	if n == 1:
		return i
	if n == 0:
		return 1
	if n % 2 == 0:
		a = pow(i,n/2)
		return a*a
	return i * pow(i,n-1)

fmem = dict()

def f(x):
#	print x	
	if x in fmem:
		return fmem[x]
	if x == 89:
		return 89
	if x == 1:
		return 1
	ret = 0
	xx = x
	while x > 0:
		j = x % 10
		ret += square(j)
		x /= 10
	fmem[xx]=ret	
	return ret

gmem = dict()

def g(x):
	if x in gmem:
		return gmem[x]
	if x == 1 or x == 89:
		return x
	ret = g(f(x))	
	gmem[x] = ret
	return ret


print g(44)

count = 0
lim = 10e6
for i in xrange(2,lim+1):
	if g(i)==89:
		count += 1
print count

