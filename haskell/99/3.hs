element_at :: [a] -> Integer -> Maybe a
element_at [] _ = Nothing
element_at xs i = element_at' xs i 1
  where
    element_at' :: [a] -> Integer -> Integer -> Maybe a
    element_at' [] _ _ = Nothing
    element_at' (x:xs) i ii = if ii <= 0 then Nothing
      else if i == ii then Just x
        else element_at' xs i (ii + 1)
    n = toInteger $ length xs
