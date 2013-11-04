mem = dict()
marks = ['L','O','A']
good = []

def bad(n, curr, cons_a, late_num, accum = ""):
	if cons_a >= 3:
		return 0
	if late_num >= 2:
		return 0
	if n == 1:
		return 1

	memk = (n,curr,cons_a,late_num)
	if memk in mem:
		return mem[memk]

	answer = 0

	for mark in marks:
		accumr = accum 
		if mark == 'O':
			answer += bad(n-1, mark, 0, late_num, accumr  )
		if mark == 'L':
			answer += bad(n-1, mark, 0, late_num + 1, accumr)
		if mark == 'A':
			answer += bad(n-1, mark, cons_a + 1, late_num, accumr )

	mem[memk] = answer
	return answer

n = 30
answer = 0
for mark in marks:
	late_num = 0
	cons_a = 0
	if mark == 'A':
		cons_a = 1
	if mark == 'L':
		late_num = 1
	answer += bad(n,mark,cons_a,late_num, mark)

print sorted(good)
print len(good)
print len(mem)
print answer
	
