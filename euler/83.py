m_lines = open("83_in.txt").read().splitlines()
matrix = []
for line in m_lines:
	matrix.append( map( lambda x: int(x), line.split(',') ) )

infinity = 999999999

delta = [(-1,0), (1,0), (0,1), (0,-1)]

def solve( ):
	m = len(matrix)
	n = len(matrix[0])
	print m,n
	dist = []
	for i in xrange(m):
		dist.append( map( lambda x: infinity, range(n)))
	dist[0][0] = matrix[0][0]
	for j in xrange( n ):
		for i2_u in xrange( m ):
			for j2_u in xrange( n ):
				for d in delta:
					i2_v = i2_u+d[0]
					j2_v = j2_u+d[1]
					if i2_v < 0 or j2_v < 0 or i2_v >= m or j2_v >= n:
						continue
					t = dist[i2_u][j2_u] +  matrix[i2_v][j2_v] 
					if t < dist[i2_v][j2_v]:
						dist[i2_v][j2_v] = t
	#print dist
	return dist[m-1][n-1]


print solve()
	
