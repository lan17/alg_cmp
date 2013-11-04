def subset_sum( S, T ):
	Sn = len(S)
	table = [[False]*(T+1)]*(Sn+1)	
	print table
	for t in xrange(1,T+1):
		if t == S[0]:
			table[1][t] = True
	print table
	for i in xrange(2,Sn+1):
		for t in xrange(1,T+1):
			if t - S[i-1] < 0:
				table[i][t] = table[i-1][t]
			else:
				ct = table[i-1][t] or table[i-1][t-S[i-1]]
				print i,t,ct
				table[i][t] = ct
	print table
	return table[Sn][T]
	
def subset_sum_rec( S, T, i=0, sum=0, mem = None ):
	if mem == None:
		mem = {}
		for j in xrange(len(S)):
			if subset_sum_rec( S, T, j, S[j], mem ):
				return True
		return False
	print i,sum
	if sum == T:
		return True
	if sum > T:
		return False
	if i == len(S)-1:
		return False
	key = (i,sum)
	if key in mem:
		return mem[key]
	answer = False
	for j in xrange(i+1,len(S)):
		answer = answer or subset_sum_rec( S, T, j, sum + S[j], mem )
	mem[key] = answer
	return answer

S = [1,2,4]
T = 8
print subset_sum(sorted(S),T)
print subset_sum_rec(S, T)

#def partition_sum( S ):
	
