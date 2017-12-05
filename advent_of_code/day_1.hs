import Data.Char

{--
captcha' _ [] = 0
captcha' h [x] = if h == x then digitToInt h else 0
captcha' h (x:y:xs) = if x == y then (digitToInt x) + r else 0 + r
    where r = captcha' h (y:xs)
captcha xx@(x:xs) = captcha' x xx
--}

captcha :: Int -> [Char] -> Int
captcha n s = sum $ map (\(x,y) -> if x == y then digitToInt x else 0) $ zip s ss
    where
        ss = drop n s ++ take n s

captcha_part1 = captcha 1
captcha_part2 s = captcha ((length s) `div` 2) s