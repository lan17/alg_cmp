#!/usr/bin/python

import sys, math

data = open(sys.argv[1], 'r').read().splitlines()

a = int(sys.argv[2] ) -1 
b = int(sys.argv[3] ) -1

a_x = float( data[a].split()[1] )
a_y = float( data[a].split()[2] )
b_x = float( data[b].split()[1] )
b_y = float( data[b].split()[2] )

print math.sqrt( math.pow(a_x-b_x,2) + math.pow( a_y-b_y, 2 ) )


