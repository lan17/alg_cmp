module GCJ (gcjMain, primes) where

import Data.List
import System.Environment
import Criterion.Measurement

-- I/O helper functions

-- Process entire GCJ style problem input and produce GCJ style output.
solutionsToString :: ([Char] -> [Char]) -> [Char] -> [Char]
solutionsToString solveFn content = intercalate "\n" solutions
    where
        solutions = map solveCase $ zip [1..] $ tail cases
        solveCase = \(case_num, caseInput) -> "Case #" ++ (show case_num) ++ ": " ++ solveFn(caseInput)
        cases = lines content

gcjMain :: ([Char] -> [Char]) -> IO ()
gcjMain solveFn = do
    args <- getArgs
    let inputFileName = args !! 0
    let outputFileName = inputFileName ++ ".out"
    content <- readFile $ args !! 0

    startTime <- getCPUTime

    writeFile outputFileName $ solutionsToString solveFn content

    endTime <- getCPUTime
    putStrLn $ "Took " ++ secs (endTime - startTime) ++ " to solve"

-- Algos

-- Primes.  Taken from https://wiki.haskell.org/Prime_numbers#Tree_merging
_Y   :: (t -> t) -> t
_Y g = g (_Y g)                -- multistage, non-sharing,  g (g (g (g ...)))
    -- g (let x = g x in x)    -- two g stages, sharing
primes = 2 : _Y ((3:) . gaps 5 . joinT . map (\p-> [p*p, p*p+2*p..]))

-- joinL ((x:xs):t) = x : union xs (joinL t)
joinT ((x:xs):t) = x : union xs (joinT (pairs t))    -- set union, ~=
  where  pairs (xs:ys:t) = union xs ys : pairs t     --    nub.sort.concat

gaps k s@(x:xs) | k < x = k:gaps (k+2) s       -- ~= [k,k+2..]\\s,
                | True  =   gaps (k+2) xs      --   when null(s\\[k,k+2..])
