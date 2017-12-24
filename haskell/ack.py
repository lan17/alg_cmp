mem = dict()
def ack(m, n):
	#print m, n
	key = (m,n)
	if key in mem:
		return mem[key]
	ret = 0 
	if m == 0:
		ret = n + 1
	elif n == 0:
		ret = ack(m - 1, 1)
	else:
		ret = ack(m - 1, ack(m, n - 1))
	mem[key] = ret
	return ret

for m in xrange(0, 3):
	for n in xrange(0,5):
		ack(m,n)
print ack(3,2)
