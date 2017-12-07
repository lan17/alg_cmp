import Debug.Trace

split' xx@(x:xs) delim accum@(h:hs) | trace ("split' " ++ show xx ++ ", " ++ show delim ++ ", " ++ show accum) False = undefined
split' "" _ accum = reverse accum
split' (x:xs) delim accum@(h:hs) = split' xs delim stack
  where
    stack = if x == delim then [] : accum else (h ++ [x]) : hs

split str delim = split' str delim [[]]

str_2_int str = read :: Integer
