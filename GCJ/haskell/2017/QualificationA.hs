import Data.List.Split
import Debug.Trace

import GCJ

notGood pancakes = not $ any (\x -> x == '-') pancakes

flipJ pancakes j = (map (\x -> if x == '-' then '+' else '-') $ take j pancakes) ++ (drop j pancakes)

negative_infinity = -1 * 1000 * 2

solve' :: [Char] -> Int -> Int
--solve' pancakes k | trace (show pancakes ++ " : " ++ show k) False = undefined
solve' [] _ = 0
solve' (x:[]) k = if x == '-' then negative_infinity else 0
solve' (first:rest@pancakes) k = if first == '-' then
    if length rest < (k - 1)  then negative_infinity else 1 + solve' (flipJ rest (k - 1)) k
    else solve' rest k

solve str = if solution < 0 then "IMPOSSIBLE" else show solution
    where
          solution = solve' pancakes k
          pancakes = strParts !! 0
          k = read (strParts !! 1) :: Int
          strParts = splitOn " " str

main = gcjMain solve
