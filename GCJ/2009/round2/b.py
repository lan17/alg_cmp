#!/usr/bin/python

import sys

INF = 1e9

inp = sys.stdin.read().splitlines()

T = int(inp[0])
line = 1


for case in xrange(1,T+1):
	R = int( inp[line].split()[0] )
	C = int( inp[line].split()[1] )
	F = int( inp[line].split()[2] )
	line += 1
	board = []
	dp = []
	for r in xrange(R):
		board.append( inp[line] )
		line += 1 
		dp.append([INF]*C)
	for i in xrange( C ):
		if board[0][i] == '.':
			dp[0][i] = 0
		else:
			break
	for row in xrange( 1, R ):
		for col in xrange( C ):
			if board[row][col]=='.':
				t = row - 1
				while t >= 0 and board[t][col] == '.' and t <= F:
					
					t -= 1
				
						board[tt][col] = INF
	
	print "Case #" + str(case) + ": " + str(board) + str(dp)
