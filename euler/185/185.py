#!/usr/bin/python

import sys

inp = sys.stdin.read().splitlines()
data=[]
for line in inp:
	s = line.split(";")
	nums = map(lambda x:int(x), s[0].strip() )
	corr = int(s[1].split()[0])
	data.append( (nums,corr) )
	
data = sorted(data,key=lambda x: x[1])
possib = map( lambda x: filter( lambda y: y != x, range(9+1) ), data[0][0] )

data = data[1:]
#data = sorted(data,key=lambda x:x[1])
#data.reverse()

print data
print possib

def solve( p, i ):
	global data
	if i >= len(data):
		return None
	cnt = 0
	done = True
	for d in xrange( len(p) ):
		if len(p[d]) > 1:
			done = False
		if data[i][0][d] in p[d]:
			cnt += 1
	if done:
		return p
	if cnt < data[i][1]:
		return None
	cnt = data[i][1]
	k = 0
	answer = None
	while cnt > 0:
		pos = p
		while not data[i][0][k] in pos[k]:
			k += 1
		if k >= len(data[i][0]):
			return None
		cnt -= 1
		pos[k] = [ data[i][0][k] ]
		sol = solve(pos,i + 1) 
		answer = answer if sol == None else sol
	return answer
	
print solve( possib, 0 )
