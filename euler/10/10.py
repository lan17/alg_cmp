isprimes=[False,False,True]
primes=[2]
lim = 2e6
ret = 2
for i in xrange( 3, lim):
        isprimes.append(True)
for i in xrange( 3, lim,2 ):
        if not isprimes[i]:
                continue
	ret += i
        k = 2
        while i *k < lim:
                isprimes[i*k] = False
                k += 1

print ret

