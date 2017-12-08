def solve(n):

  direction = 0

  sums = dict()
  sums[(0,0)] = 1
  sums[(1,0)] = 1

  dx = [0, -1, 0, 1]
  dy = [-1, 0, 1, 0]

  sdx = dx + [1, -1, -1, 1]
  sdy = dy + [-1, -1, 1, 1]

  x, y = 1, 0
  i = 2
  side = 3
  left = 0

  done_with_sums = False

  while i < n:
    i += 1
    x += dx[direction]
    y += dy[direction]

    sums[(x,y)] = 0
    for d in xrange(0, 8):
      xx = x + sdx[d]
      yy = y + sdy[d]

      if (xx, yy) in sums:
        sums[(x,y)] += sums[(xx,yy)]

    if not done_with_sums and sums[(x,y)] > n:
      done_with_sums = True
      print "DING DING DING, ", sums[(x,y)]

    #print i, x, y

    if left == 0:
      direction = (direction + 1) % 4
      #print "switching direction to ", direction
      if direction == 0:
        left = side
        side += 2
        #print "incrementing side", side
      else:
        left = side - 1 if direction != 3 and direction != 0 else side

    left -= 1

  #print x, y
  return abs(x) + abs(y), sums[(x,y)]

for i in xrange(3, 24):
  print i, solve(i)

print solve(1024)
print solve(325489)
