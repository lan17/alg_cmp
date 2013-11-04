import Data.List (union)
import Data.List (tails) 
import Data.Char (digitToInt)
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
primesTo m = 2 : eratos [3,5..m]  where
   eratos []     = []
   eratos (p:xs) = p : eratos (xs `minus` [p*p,p*p+2*p..])

-- prob 5
gcd1 a 0 = a
gcd1 a b = gcd1 b (a `mod` b)
-- least common multiple  lcm(a,b)=abs(a*b)/(gcd(a,b))
lcm1 a b = (a * b) `div` (gcd1 a b)
prob5 = foldr1 lcm1 [1..20]
-- prob6
sumOfSquares n = sum [ x^2 | x <- [1..n] ]
squareOfSum n = (sum [1..n])^2
prob6 n = abs (sumOfSquares n - squareOfSum n)
-- prob8
prob8 = do str <- readFile "prob8.txt";
           let digits = map digitToInt (concat $ lines str);
           print $ maximum $ map (product . take 5 ) (tails digits )


main = prob8
