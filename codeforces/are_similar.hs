diff [] []  = []
diff (x:xs) (y:ys) = if x == y then diff xs ys else (x, y) : diff xs ys
