import sys

infinity = 99999999

m_lines = open("82_in.txt").read().splitlines()
matrix = []
for line in m_lines:
	matrix.append( map( lambda x: int(x), line.split(',') ) )
m = len(matrix)
n = len(matrix[0])

delta = [ (1,0), (0,1), (-1,0)]

def solve( c_i ):
	m = len(matrix)
	n = len(matrix[0])
#	print m,n
	dist = []
	for i in xrange(m):
		dist.append( map( lambda x: infinity, range(n)))
	dist[c_i][0] = matrix[c_i][0]
	for i in xrange( m ):
#		print i
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
	ret = dist[0][n-1]
	for i in xrange( 1, n ):
		ret = min( ret, dist[i][n-1] )
	return ret

"""
ret = infinity
for c_i in xrange( 0, m ):
	print c_i
	ret = min(ret, solve( c_i ) )
print ret
"""
print sys.argv[1], solve(int(sys.argv[1] ) )

