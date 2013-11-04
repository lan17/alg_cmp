#!/usr/bin/python

import sys

# read input from standard input
inp = sys.stdin.read().splitlines() # read from standard input into a list of lines
tree = {} # tree is a dictionary
for line in inp:
	data = line.split(":")
	id = int(data[0])
	entry = float(data[1])
	children = None if len(data[2]) == 0 else map( lambda x: int(x), data[2].split(",") ) #ternary operator in python.  May gods help me.
	tree[id] = (entry,children)

# memoize dictionary
mem = {}

"""
Recursive DFS search with memoization.

Finds the sum of a minimum weighted vertex cover.
tree is a dictionary (map) of form: id -> (weight,(adjacency list of ids))
node is root id
take is a boolean which is an assumption of whether root node is in vertex cover or not.

Algorithm works by computing minimum weighted vertex cover on a subtree with root node assumed to be either in the solution or not.

If root is part of solution then we have to include its weight in minimum sum.
Each child's minimum solution is then added to the sum.
If root node is assumed to be taken then for each child we make two recursive calls as the child may or may not be taken itself in globally optimal solution.

If root is assumed to not be taken then the only possible solution for child is to assume that it must be taken.  Otherwise we lose property of vertex cover.

Notice that once we compute an optimal solution for some subtree with set taken value, we can reuse such solution, so we memoize it in a dictionary.

Running time is O(2N) == O(N).  Space complexity is exactly 2N.  N here is number of nodes in tree.

This is because for each node we compute two solutions, and we use memoization to not repeat done work.  Therefore we visit each node twice.

This is reverse Dynamic Programming or top-bottom DP.  It is not pseudo-polynomial, but truly polynomial because it is bounded by N only.
"""
def solve( tree, node, take ):
	children = tree[node][1]
	leaf = children == None
	weight = tree[node][0]
	if leaf:
		if take:
			return weight
		return 0

	key = (node, take)
	if key in mem:
		return mem[key]
	
	"""
	answer = weight if take else 0
	for child in children:
		if take:
			answer += min( solve( tree, child, True ), solve( tree, child, False ) )
		else:
			answer += solve( tree, child, True )
	"""
	# below line is equivalent to commented out section above.
	answer = reduce( lambda x,y: x + ( min( solve( tree, y, True ), solve( tree, y, False ) ) if take else solve( tree, y, True ) ), children, weight if take else 0 )
	
	mem[key] = answer
	return answer
	
#print tree

# compute global solution for tree.
sol = min( solve(tree,0,True), solve( tree, 0, False ) )

print sol
