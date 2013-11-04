from sets import Set

curr = []

mem = dict();
#mem[0] = 1;

def ways( num, c ):
	#print num
	if num < 0:
		return 0
	if num == 0:
		return 1
	if num == 1:
		return 1
	if c < 0:
		return 0
	if (num,c) in mem:
		return mem[(num,c)]
	answer = ways( num, c - 1 ) + ways( num - curr[c], c )
	mem[(num,c)] = answer
	return answer
	

def solve( num ):
	table = [0]*(num+1)
	for coin in curr:
		j = coin
		while j <= num:
			table[j] = table[j] + 1
			j += coin
	print table
	return table[num]

num = 100;
for i in xrange(1,num):
	curr.append(i)
			
print ways(100,98)
print solve( 100 )
