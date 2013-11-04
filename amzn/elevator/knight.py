import sys

EMPTY_CELL=0
TAKEN_CELL=1
ATTACKED_CELL=2

boardSize = int(sys.argv[1])
board = None

def resetBoard():
    global board
    board = [[0]*boardSize for x in xrange(boardSize)]

kd = [(-1,-2),(1,-2),(2,-1),(2,1),(1,2),(-1,2),(-2,1),(-2,-1)]

def good( i, j,mark,unmark):
    for k in xrange(len(kd)):
        ii = i + kd[k][0]
        jj = j + kd[k][1]
        if ii < 0 or jj < 0 or ii >= boardSize or jj >= boardSize:
            continue
        if not mark and board[ii][jj] == TAKEN_CELL:
            return False
        if mark:
            if not unmark:
                board[ii][jj] = ATTACKED_CELL
            else:
                board[ii][jj] = EMPTY_CELL
    return True


def ways(cK,mK,si):
    if cK == mK:
        return 1
    ret = 0
    for sii in xrange(si,boardSize*boardSize):
        i = sii/boardSize
        j = sii%boardSize
        if board[i][j] != EMPTY_CELL:
            continue
        if good(i,j, False, False):
            board[i][j]=True
            good(i,j,True,False)
            ret += ways(cK+1,mK,sii)
            good(i,j,True,True)
            board[i][j]=False
    return ret


resetBoard()
print ways(0,int(sys.argv[2]),0)

ans = 0
a = 0
b = 0
i = 1
while True:
    resetBoard()
    a = ways(0,i,0)
    print i, a
    if a == b:
        break
    i += 1
    ans += a
    b = a
print ans

