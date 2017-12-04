import Data.Char

captcha' _ [] = 0
captcha' h [x] = if h == x then digitToInt h else 0
captcha' h (x:y:xs) = if x == y then (digitToInt x) + r else 0 + r
    where r = captcha' h (y:xs)
captcha xx@(x:xs) = captcha' x xx



