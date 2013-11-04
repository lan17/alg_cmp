mem={}

def in_list( l, n ):
	if n in mem:
		return mem[n]
	a = 0
	b = len( l ) - 1
	p1 = -1
	ret = False
	while( a < b ):
		p = (a + b )/2
		if p1 == p:
			break
	#	print a,b,p,l[p]
		if l[p] == n:
			ret = True
			break
		if l[p] > n:
			b = p
		if l[p] < n:
			a = p
		p1 = p
	mem[n] = ret
	return ret

def P(n):
	return (n*(3*n-1))/2

lim = int(1e6)

pents = [0]*lim
for i in xrange(1,lim+1):
	pents[i-1] = P(i)

print pents[0:20]
print in_list(pents,17)
print in_list(pents,17)

#print pents

for i in xrange( 4, len(pents ) ):
	diff = pents[i];
	for j in xrange( i+1, len(pents)/2 ):
		pj = pents[j]
		pk = diff + pj;
		if in_list(pents,pk ) and in_list(pents,pk+pj):
			print pj,pk,pk+pj,diff
	print i
			
		
