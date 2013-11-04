fact=1
for i in xrange(1,101):
	fact*= i
print fact

ret=0
while fact > 0:
	ret += fact % 10
	fact /= 10

print ret
