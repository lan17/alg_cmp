from sets import Set

curr = [1,2,5,10,20,50,100,200]

mem = dict();

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

def ways2( num, curr_num, c, mem ):
	if curr_num > num:
			return 0
	if curr_num == num:
			return 1
	

def solve( num ):
	table = [0]*(num+1)
	for coin in curr:
		j = coin
		while j <= num:
			table[j] = table[j] + 1
			j += coin
	print table
	return table[num]
			

print ways( 200, 7 )
print solve( 200 )
