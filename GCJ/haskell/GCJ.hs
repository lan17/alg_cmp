module GCJ where

import Data.List
import System.Environment

-- Process entire GCJ style problem input and produce GCJ style output.
solutionsToString :: ([Char] -> [Char]) -> [Char] -> [Char]
solutionsToString solveFn content = intercalate "\n" solutions
    where
        solutions = map solveCase $ zip [1..] $ tail cases
        solveCase = \(case_num, caseInput) -> "Case #" ++ (show case_num) ++ ": " ++ solveFn(caseInput)
        cases = lines content

gcjMain :: ([Char] -> [Char]) -> IO ()
gcjMain solve = do
    args <- getArgs
    let inputFileName = args !! 0
    let outputFileName = inputFileName ++ ".out"
    content <- readFile $ args !! 0
    writeFile outputFileName $ solutionsToString solve content