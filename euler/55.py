def isPalindrome(n):
	s = str(n)
	return s == s[::-1]

def reverse( n ):
	s = str(n)
	return int(s[::-1])

def is_lychrel(n):
	for i in xrange( 50 ):
		n = n + reverse(n)
		if isPalindrome( n ):
			return True
	return False

answer = 0
for i in xrange( 10, 10000 ):
	if not is_lychrel( i ):
		answer += 1

print answer
