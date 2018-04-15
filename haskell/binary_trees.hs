data Tree = Nil | Node Tree Tree deriving Show

uniqueTrees 0 = [Nil]
uniqueTrees n = [Node left right | i <- [0..(n - 1)], left <- uniqueTrees i, right <- uniqueTrees (n - i - 1)]
