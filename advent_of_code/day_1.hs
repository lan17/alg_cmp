import Data.Char

captcha :: Int -> [Char] -> Int
captcha n s = sum $ map (\(x,y) -> if x == y then digitToInt x else 0) $ zip s ss
    where
        ss = drop n s ++ take n s

captcha_part1 = captcha 1
captcha_part2 s = captcha ((length s) `div` 2) s