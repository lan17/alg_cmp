{-# LANGUAGE FlexibleContexts #-}

import Data.List
import Control.Monad.State
import Control.Monad.ST
import Data.Array.ST

changeValInList list index newValue = take index list ++ [newValue] ++ drop (index + 1) list

type Rule = (Int -> Int)
type Solution = Int
type SimulationState = (Int, Int, [Int], Int)

part_1_rule :: Int -> Int
part_1_rule = (+1)

part_2_rule x = if x >= 3 then x - 1 else x + 1

simulate :: (Int -> Int) -> State SimulationState Solution
simulate rule =  do
    (stepsSoFar, position, board, length) <- get
    let valueAtPosition = board !! position
    let newPosition = position + valueAtPosition
    put (stepsSoFar + 1, newPosition, changeValInList board position $ rule valueAtPosition, length)
    if newPosition < 0 || newPosition >= length
        then return stepsSoFar
        else simulate rule

solve :: Rule -> [Int] -> Int
solve rule instructions = evalState (simulate rule) (1, 0, instructions, length instructions)

solve_fast' :: Rule -> STUArray s Int Int -> Int -> Int -> Int -> ST s Int
solve_fast' rule board length stepsSoFar position = do
    if position < 0 || position >= length
        then return stepsSoFar
        else do
            valueAtPosition <- readArray board position
            let newPosition = position + valueAtPosition
            let newValue = rule valueAtPosition :: Int
            writeArray board position newValue
            solve_fast' rule board length (stepsSoFar + 1) newPosition

solve_fast :: Rule -> [Int] -> Int
solve_fast rule instructions = runST $ do
  let n = length instructions :: Int
  board <- newListArray (0, n) instructions :: ST s (STUArray s Int Int)
  solve_fast' rule board n 0 0

main = do
    content <- readFile "day_5.in"
    let instructions = map (\x -> read x :: Int) $ lines content
    --putStrLn $ show $ solve part_1_rule [0, 3, 0, 1, -3]
    --putStrLn $ show $ solve part_1_rule instructions

    --putStrLn $ show $ solve part_2_rule [0, 3, 0, 1, -3]
    --putStrLn $ show $ solve part_2_rule instructions

    putStrLn $ show $ solve_fast part_1_rule [0, 3, 0, 1, -3]
    putStrLn $ show $ solve_fast part_2_rule [0, 3, 0, 1, -3]
    putStrLn $ show $ solve_fast part_1_rule instructions
    putStrLn $ show $ solve_fast part_2_rule instructions
