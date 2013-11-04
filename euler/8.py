import os

number=open("8_in.txt").read()
ans = 0
for i in xrange( 0, len(number)-5):
	p =1
	for j in xrange(i,i+5):
		p *= int( number[j] )
	ans = max(ans, p )
print ans	
