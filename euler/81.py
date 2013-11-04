m_lines = open("81_in.txt").read().splitlines()
matrix = []
for line in m_lines:
	matrix.append( map( lambda x: int(x), line.split(',') ) )
m = len(matrix)
n = len(matrix[0])

mem = dict()
for i in xrange( 0,m ):
	mem[i] = dict()
	for j in xrange( 0, n ):
		mem[i][j] = -1

def solve( i, j ):
	if i >= m or j >= n:
		return 9999999999;
	if i == m - 1 and j == n - 1:
		return matrix[i][j]
	if mem[i][j] != -1:
		return mem[i][j]
	mem[i][j] = matrix[i][j] + min( solve(i+1,j), solve(i,j+1) )
	return mem[i][j]
print solve(0,0)


