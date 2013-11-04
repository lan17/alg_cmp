def make_shit():
	ret = ""
	i = 1
	while len(ret) < 1000001:
		ret += str(i)
		i += 1
	return ret

shit = make_shit()
t = 1
answer = 1
while t <= int(1e6):
	answer *= int(shit[t-1])
	t *= 10
print answer
