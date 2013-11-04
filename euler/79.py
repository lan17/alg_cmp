followed = []
follows =  []

for i in xrange(0,10):
	followed.append([])
	follows.append([])
	for j in xrange( 0,10):
		followed[i].append(0)
		follows[i].append(0)

def put_num(n):
	t = str(n)

	a = int(t[0])
	b = int(t[1])
	c = int(t[2])

	followed[a][b] = 1
	followed[a][c] = 1
	followed[b][c] = 1
		
	follows[c][b] = 1
	follows[b][a] = 1
	follows[c][a] = 1

def get_followed( i ):
	ret = []
	for t in xrange( len(followed[i]) ):
		if followed[i][t] == 1:
			ret.append(t)
	return ret
		
def search(  i ):
	foll = get_followed(i)
	if len( foll ) == 0:
		return [i]
	ret = []
	for f in foll:
		r = search(f)
		if len(r) > len(ret):
			ret = r
	ret = [i] + ret
	return ret
		
		

numbers = open("79_in.txt").read().splitlines()
for n in numbers:
	put_num(n)

for i in xrange( len( followed ) ):
	print i, followed[i]

print "======="

for i in xrange( len( followed ) ):
	print i, follows[i]

print search(7)
