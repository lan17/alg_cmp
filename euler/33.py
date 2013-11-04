for i in xrange( 10, 100 ):
	for j in xrange( i + 1, 100 ):
		t = float(i) / float(j)
		i1 = str( i )
		j1 = str( j )
		for k1 in xrange( len( i1 ) ):
			for l1 in xrange( len( j1 ) ):
				if i1[k1] == j1[l1]:
					if i1[k1] != '0':
						k11 = i1[0]
						if k1 == 0:
							k11 = i1[1]
						j22 = j1[0]
						if l1 == 0:
							j22 = j1[1]
						if j22 != '0':
							t1 = float( k11 ) / float( j22 )
							#print t1, t, i1[k1], j1[l1]
							if t1 == t:
								print i, j
