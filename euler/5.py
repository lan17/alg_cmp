#!/usr/bin/env python

end=11

num = 1
for i in xrange(2,end+1):
	print i
	num *= i
	print num
print num

i = 20
while i <= num:
	found = True
	for d in xrange(2,end+1):
		if i % d != 0:
			found = False
			break;
	if found:
		print i
		break
	i += 1
		
