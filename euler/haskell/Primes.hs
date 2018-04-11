module Primes(primes, primeFactors) where

import Data.List

primeFactors :: Integer -> [Integer]
primeFactors 1 = []
primeFactors x = [p] ++ primeFactors (x `div` p)
    where p = head $ [prime | prime <- primes, x `mod` prime == 0]

-- Prime algorithm taken from https://wiki.haskell.org/Prime_numbers#Tree_merging
_Y   :: (t -> t) -> t
_Y g = g (_Y g)                -- multistage, non-sharing,  g (g (g (g ...)))
    -- g (let x = g x in x)    -- two g stages, sharing
primes = 2 : _Y ((3:) . gaps 5 . joinT . map (\p-> [p*p, p*p+2*p..]))

-- joinL ((x:xs):t) = x : union xs (joinL t)
joinT ((x:xs):t) = x : union xs (joinT (pairs t))    -- set union, ~=
  where  pairs (xs:ys:t) = union xs ys : pairs t     --    nub.sort.concat

gaps k s@(x:xs) | k < x = k:gaps (k+2) s       -- ~= [k,k+2..]\\s,
                | True  =   gaps (k+2) xs      --   when null(s\\[k,k+2..])

