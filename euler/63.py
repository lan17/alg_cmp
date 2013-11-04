def num_dig(i):
	ret = 0
	while i > 0:
		i /= 10
		ret +=1
	return ret

def pow(i,n):
	if n == 1:
		return i
	if n == 0:
		return 1
	if n % 2 == 0:
		a = pow(i,n/2)
		return a*a
	return i * pow(i,n-1)

count = 1
i = 2
while True:
	a = pow(2,i)
	ac = num_dig(a)
	if( ac == 1 ):
		i += 1
		continue
	print i, a, ac
	if ac <  i:
		break
	if ac == i:
		count += 1
	j = 3
	while True:
		a = pow(j,i)
		ac = num_dig(a)
		if ac < i:
			break
		if ac == i:
			count += 1
			break
		j += 1	
	i += 1
	print count

print count
print pow(3,7)
