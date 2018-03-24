import System.Environment
import Data.Bits
import Data.Char
import Data.List
import Numeric (showIntAtBase)

digitMask :: Int -> Int
digitMask 0 = 0
digitMask x = (.|.) (shift 1 p) (digitMask $ x `div` 10)
    where p = x `mod` 10

doneMask = digitMask 1234567890

solve :: [Char] -> [Char]
solve input = if answer == -1 then "INSOMNIA" else show answer
    where
        answer = solve' x 1 (digitMask x)
        x = read input :: Int

solve' :: Int -> Int -> Int -> Int
solve' 0 _ _ = -1
solve' x i m = if m == doneMask then x * i else solve' x (i + 1) ((.|.) m $ digitMask $ x * (i+1))

main = do
    args <- getArgs
    -- putStrLn $ showIntAtBase 2 intToDigit (digitMask $ read $ args !! 0) ""
    let inputFileName = args !! 0
    let outputFileName = inputFileName ++ ".out"
    content <- readFile $ args !! 0
    let cases = lines content
    let solutions = map (\(case_num, input) -> "Case #" ++ (show case_num) ++ ": " ++ solve(input)) $ zip [1..] $ tail cases
    writeFile outputFileName $ intercalate "\n" solutions
