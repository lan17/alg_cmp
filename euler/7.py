isprimes=[False,True,True]
primes=[2]
lim = 1000000
for i in xrange( 3, lim):
	isprimes.append(True)
for i in xrange( 3, lim,2 ):
	if not isprimes[i]:
		continue
	primes.append(i)
	if len(primes) > 10001:
		break
	k = 2
	while i *k < lim:
		isprimes[i*k] = False
		k += 1

print primes[10000]

