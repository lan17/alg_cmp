from MillerRabin import miller_rabin 

start=int(1e16)+1
count=0
s = 0
while count < 1e6:
	if miller_rabin(start):
		count += 1
		s += start
		print start, count
	start +=2

print count
print s


