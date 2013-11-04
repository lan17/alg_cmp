import sys

def is_palindrome(x):
	t = []
#	print x
	while True:
		if x < 1:
			break
		t.append( x % 10 )
		x /= 10
#	print x
	#print t
	for i in range(0,len(t)-1):
		if t[i] != t[len(t)-i-1]:
			return False
	#print t
	return True

largest = 0

for a in xrange(999, 100, -1):
	for b in xrange(a,100,-1):
		if a * b <= largest:
			break
		if is_palindrome(a*b):
			largest = max( largest, a*b)
			print a
			print b
			print largest

print largest
			
		
		
