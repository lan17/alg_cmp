#!/usr/bin/python 

import sys

def satisfies(cust,malted):
		for i in xrange( 1, len( malted ) + 1 ):
			if i in cust[0] and cust[1] == i and malted[i-1]:
				return True
			if i in cust[0] and cust[1] != i and not malted[i-1]:
				return True
		return False

counter=0

def solve( customers, N ):
	global counter
	sol = [False]*N
	while True:
		good = True
		for cust in customers:
			if sol[cust[1]-1]:
				continue
			counter +=1
			s = satisfies(cust, sol)
			if not s:
				if cust[1] == -1:
					return None
				sol[cust[1]-1] = True
				good = False
				break
		if good:
			return sol
			
			
inp = sys.stdin.read().splitlines()

C = int(inp[0])
line = 1

for CASE in xrange( 1, C+1 ):
	N = int(inp[line])
	M = int(inp[line+1])
	line += 2
	customers = []
	for m in xrange(M):
		cust = inp[line].split()
		T = int(cust[0])		
		
		likes = []
		malted = -1
		for j in xrange(1,1+T*2,2):
			drink = int( cust[j] )
			if int(cust[j+1]) == 1:
				malted = drink
			likes.append(drink)
		customers.append( (likes,malted) )		
		line += 1
	
	sol = solve( customers, N )
	print "Case #"+str(CASE)+":",
	if sol == None:
		print "IMPOSSIBLE"
	else:
		for v in sol:
			print 1 if v else 0,
		print ""
	#print N,M
	#print counter
