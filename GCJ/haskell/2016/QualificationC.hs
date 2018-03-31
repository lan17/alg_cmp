import Data.List.Split
import Data.List
import Numeric (showHex, showIntAtBase)
import Data.Char (intToDigit)
import Control.Parallel
import Control.Parallel.Strategies

import GCJ

-- Convert an integer to base 2 String
intAsBinary :: Integer -> [Char]
intAsBinary x = showIntAtBase 2 intToDigit x ""

digitToInt :: Char -> Integer
digitToInt '1' = 1
digitToInt '0' = 0

-- map from jam coin as list of bits to its representations in different radices.
toNumbersFromDigits :: [Integer] -> [Integer]
toNumbersFromDigits digits = map toNumbers' [2..10]
    where toNumbers' base = foldr (\(pos, digit) accum -> accum + digit * base ^ pos) 0 (zip [0..] $ reverse digits)

toNumbersFromString :: [Char] -> [Integer]
toNumbersFromString str = toNumbersFromDigits $ map digitToInt str

toNumbersFromMask :: Integer -> [Integer]
toNumbersFromMask mask = toNumbersFromString $ intAsBinary mask

divisors = take 5 primes

-- Generate lazy list of Jam Coins of length N
goodJamCoins n = [x | x <- [start, (start + 2)..], checkJamCoinBases $ toNumbersFromMask x]
    where start = 2 ^ (n - 1) + 1
          checkJamCoinBases nums = foldr (&&) True $ map isNotPrimeNumber nums
          isNotPrimeNumber x = any (\divisor -> x /= divisor && x `mod` divisor == 0) divisors

-- Map jam coin value in different base to the first divisor in that base.
getJamCoinDivisors :: [Integer] -> [Integer]
getJamCoinDivisors jamCoinBases = map (\b -> head [divisor | divisor <- divisors, b `mod` divisor == 0]) jamCoinBases

-- Solve individual case given N and J and output a String
getJamCoins :: Int -> Int -> [Char]
getJamCoins n j = intercalate "\n" $ map outputJamCoinLine jamCoins
    where
        jamCoins = take j $ goodJamCoins n
        outputJamCoinLine jamCoin = intercalate " " $ [intAsBinary jamCoin] ++ jamCoinDivisorsString
            where jamCoinDivisorsString = map show $ jamCoinDivisors
                  jamCoinDivisors = getJamCoinDivisors $ toNumbersFromMask jamCoin

solve :: [Char] -> [Char]
solve caseInput = "\n" ++ getJamCoins n j
    where n = read $ inputSplit !! 0 :: Int
          j = read $ inputSplit !! 1 :: Int
          inputSplit = splitOn " " caseInput

main = gcjMain solve