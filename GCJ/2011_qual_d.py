import sys
prob = sys.stdin.read().splitlines()
for t in xrange(0,int(prob[0])):
	print "Case #"+str(t+1)+": "+str(reduce( lambda x,y: x + (1 if y[0] != y[1] else 0), zip( map( lambda x: int(x), prob[2+t*2].split() ), sorted( map( lambda x: int(x), prob[2+t*2].split() ) )), 0 ))+".000000"
