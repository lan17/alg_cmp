import sys
import copy

boardSize = int(sys.argv[1])
bitSize = 2**boardSize+1


# the ways the knight can move
kd = [(-1,-2),(1,-2),(2,-1),(2,1),(1,2),(-1,2),(-2,1),(-2,-1)]

def good( board, i ):
    j = 2
    for k in xrange(len(kd)):
        ii = i + kd[k][0]
        jj = j + kd[k][1]
        if ii < 0 or jj < 0 or ii >= boardSize or jj >= 3:
            continue
        if board[jj][ii] == 1:
            return False
    return True

def makeRow(i):
	bits = boardSize
	ret = [0]*bits
	for j in xrange(0,bits):
		if i & 1<<j:
			ret[j] = 1
	return ret

def hashRow(row):
	bits = boardSize
	ret = 0
	for j in xrange(0,len(row)):
		if row[j] == 1:
			ret |= 1 <<j
	return ret

mem = dict()

def ways( pRow, ppRow, rowNum ):
	if rowNum == 0:
		return 1
	key = (pRow,ppRow,rowNum)
	if key in mem:
		return mem[key]
	ret = 0
	lpr = makeRow(pRow)
	lppr = makeRow(ppRow)
	board = [lppr,lpr]
	board.append([])
	for i in xrange(1,bitSize):
		lir = makeRow(i)
		board[2]=lir
		god = True
		for j in xrange(0,boardSize):
			if board[2][j] == 1:
				if not good( board, j ):
					god = False
					break
		if god:
			ret += ways(i, pRow, rowNum - 1 )
	mem[key]=ret
	return ret

answer = -1
for i in xrange(1,bitSize):
	answer += ways(i,0,boardSize-1)
print answer
