lines = open("18_in.txt").read().splitlines()
tri = []
for line in lines:
	tri.append( line.split() )
mem = dict()

def longest(grid,i,j,mem):
	if mem is None:
		mem = []
		for k in xrange(0,len(grid)):
			mem.append([])
			for k1 in xrange( 0, len(grid[k])):
				mem[k].append(-1)
		return longest(grid,0,0,mem)
	if i == len(grid)-1:
		return int( grid[i][j] )
	if mem[i][j] != -1:
		return mem[i][j]
	row_len = i+1
	a = j
	b = j + 1
	mem[i][j] =  int(grid[i][j]) + max( longest(grid,i+1,a,mem), longest( grid,i+1,b,mem))
	return mem[i][j]

print longest(tri,0,0,None)
	

