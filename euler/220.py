import math


a_v = "aAbB"
b_v = "CaDb"

def genD(n):
	d = "Ea"
	for i in xrange( n ):
		dn = ""
		for j in xrange( len( d ) ):
			if d[j] == 'a':
				dn += a_v
			elif d[j] == 'b':
				dn += b_v
			else:
				dn += d[j]
		d = dn
	return d

def corner_pos( n ):
	corners = [(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1),(-1,0),(-1,1)]	

	x = 0
	y = 1
	i = n % 8
	p = pow( 2, n / 2 )
	return (corners[i][0]*p, corners[i][1]*p)
		
	

for i in xrange( 11 ):
	istr = genD(i).replace('a','').replace('b','')#.replace('A','').replace('D','')
	print str(i)+', '+str(len(istr))+ ": "+ istr

	#print i, ",", corner_pos(i)
