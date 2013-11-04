mem = dict()

def seq(n):
	if n==1:
		return 1
	if n in mem:
		return mem[n]
	n1 = n / 2 if n % 2 == 0 else 3 * n + 1
	mem[n] = 1 + seq(n1)
	return mem[n]

longest = 0
ans = 0
for i in xrange( 1000000, 1, -1 ):
	t = seq(i)
	if t > longest:
		longest = t
		ans = i
print ans
	
