module GCJ (gcjMain, primes) where

import Data.List
import System.Environment
import Criterion.Measurement
import Control.Parallel
import Control.Parallel.Strategies
import Control.DeepSeq

-- I/O helper functions
-- Process entire GCJ style problem input and produce GCJ style output.
solutionsToString :: [[Char]] -> [Char]
solutionsToString solutions = intercalate "\n" $ decoratedSolutions
    where
        decoratedSolutions = map decorateCaseSolution $ zip [1..] solutions
        decorateCaseSolution (case_num, solution) = "Case #" ++ (show case_num) ++ ": " ++ solution

gcjMain :: ([Char] -> [Char]) -> IO ()
gcjMain solveFn = do
    initializeTime

    args <- getArgs
    let inputFileName = args !! 0
    let outputFileName = inputFileName ++ ".out"
    content <- readFile $ args !! 0

    startTime <- getTime

    let cases = tail $ lines content

    let solutions = parMap rpar solveFn cases
    -- use deepseq here to force evaluation of solutions at this point.
    endTime <- solutions `deepseq` getTime

    let solutionString = solutionsToString solutions
    writeFile outputFileName $ solutionString

    putStrLn $ "Wrote to " ++ outputFileName
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
