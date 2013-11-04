
sumsquares = 0
squaresum =0
for i in xrange( 1,101):
	sumsquares += i * i
	squaresum += i
squaresum *= squaresum

print squaresum-sumsquares
