import math

def factorial(x):
	ret = 1
	for i in xrange(1, x+1):
		ret *= i
	return ret

def num_d(n):
	ret = 0
	while n > 0:
		n /= 10
		ret += 1
	return ret

facts = [0]
for i in xrange( 1, 10 ):
	facts.append( factorial(i))

numz=[]
def find( so_far, num, rec ):
	global facts, numz
#	print so_far, num, rec
	if rec > 1 and so_far == num:
		numz.append( num )
		print num
#		return
	if rec == 9:
		return
	for i in xrange( 1, 10 ):
		ss = so_far + facts[i]
		#n = num + i * int( math.pow( 10, rec ) )
		n = num * 10 + i
		find( ss, n, rec + 1 )

find( 0, 0, 0 )
print numz
