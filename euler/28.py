def l(a):
	return 2*a+2*(a-2)

def ru(n):
	return n*n

def lu(n):
	return ru(n)-n+1

def ld(n):
	return lu(n)-n+1

def rd(n):
	return ld(n)-n+1

def sumd(n,f):
	t = 0
	ans = 0
	while n > 1:
		t = f(n)
		print t
		ans += t
		n -= 2
	return ans	

def solve(n):
	return sumd(n,lu) + sumd(n,ru) + sumd(n,ld) + sumd(n,rd) + 1


#print ru_sum(5)
print "=========="
print solve(1001)
