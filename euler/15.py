mem = dict()
for i in xrange( 0,21):
	mem[i] = dict()
	for j in xrange( 0, 21):
		mem[i][j] = -1

def solve(i,j):
	if i == 20 and j == 20:
                return 1
	if i > 20 or j > 20:
		return 0
	if mem[i][j] != -1:
		return mem[i][j]

	mem[i][j] = solve(i+1,j) + solve(i,j+1)
#	print mem[i][j]
	return mem[i][j]

print solve(0,0)
