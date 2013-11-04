import os

lines = open("11_in.txt").read().splitlines()

grid = []

for line in lines:
	grid.append( line.split() )
#	print len(line.split())

x_d=[1,0,1,-1]
y_d=[0,1,1,1]

ans=0
for i in xrange(0,20):
	for j in xrange(0,20):
		for d in xrange(0,4):
			product = 1
			i1 =i
			j1=j
			for t in xrange( 0,4 ):
				product *= int(grid[i1][j1])
#				print i1
#				print j1
				i1 += x_d[d]
				j1 += y_d[d]
				if i1 >= 20 or j1 >= 20 or i1 < 0 or j1 < 0:
					product=0
					break
#			print "========"
			ans = max(ans,product)
print ans


