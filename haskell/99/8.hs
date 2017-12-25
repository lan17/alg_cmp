compress :: Eq a => [a] -> [a]
compress [] = []
compress (x:[]) = [x]
compress (x:y:xs) = z ++ kk
  where
    eq = x == y
    z = if eq then [x] else [x] ++ [y]
    kk = if eq then
