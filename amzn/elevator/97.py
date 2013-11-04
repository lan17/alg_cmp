import sys

curr = []
for i in xrange(0,10):
	curr.append(i)
mem = dict();

def ways( num, c, nn, rec ):
	if rec == 0:
		return 0
	#print num
	if num < 0:
		return 0
	if num == 0:
		print nn
		return 1
	if num == 1:
		return 1
	if c < 0:
		return 0
	if (num,c) in mem:
		return mem[(num,c)]
	answer = ways( num, c - 1, nn, rec ) + ways( num - curr[c], c,  10*nn+ curr[c], rec - 1)
	mem[(num,c)] = answer
	return answer

def numDigits(num):
	ret = 0
	while num > 0:
		num /= 10
		ret += 1
	return ret

def compDigits(num):
	ret = [1]
	d = -1
	dd = 1
	c = 1
	while True:
		d = 10**c % num
		if d == dd or d == 1:
			break
		dd = d
		ret.append(d)
		#print dd
		c += 1
	return ret

def naive( limit, digit_sum, multiple ):
	for i in xrange(multiple,limit+1,multiple):
		dig_sum = reduce( lambda x,y: x + int(y), str(i), 0 )
		if dig_sum == digit_sum:
			print i,
			

n = int( sys.argv[1] )
lim = int( sys.argv[2] )

print numDigits(lim)
print compDigits(n)
print naive(lim, n, n )
print ways(lim, 8,1, lim)
