import Data.List (union)
import Data.List (tails) 
import Data.Char (digitToInt)

import Primes

--- common functions
-- elem' a []  = False
-- elem' a as = if ((head as) == a) then True else (elem' a (tail as))
minus a b  = [ n | n <- a, not (n `elem` b)]


-- prob 1
prob1 = sum [x | x <- [1..999], x `mod` 3 == 0 || x `mod` 5 == 0 ]
-- prob 2
fibs = 0 : 1 : zipWith (+) fibs (tail fibs)
prob2 n = sum [x | x <- takeWhile (<=n) fibs, even x ]
-- prob 3
prob3 n = maximum $ primeFactors n

-- prob 5
-- least common multiple  lcm(a,b)=abs(a*b)/(gcd(a,b))
prob5 = foldr1 lcm1 [1..20]
    where
        lcm1 a b = (a * b) `div` (gcd1 a b)
        gcd1 a 0 = a
        gcd1 a b = gcd1 b (a `mod` b)
-- prob6
sumOfSquares n = sum [ x^2 | x <- [1..n] ]
squareOfSum n = (sum [1..n])^2
prob6 n = abs (sumOfSquares n - squareOfSum n)
-- prob8
prob8 = do str <- readFile "prob8.txt";
           let digits = map digitToInt (concat $ lines str);
           print $ maximum $ map (product . take 5 ) (tails digits )


main = do
    putStrLn $ show $ prob5