import Data.List
import Control.Monad.State
import Control.Monad.ST
import Data.Array.ST

type Rule = (Int -> Int)
type Solution = Int

part_1_rule :: Rule
part_1_rule = (+1)

part_2_rule :: Rule
part_2_rule x = if x >= 3 then x - 1 else x + 1


{-- Slow implementation using state monad -}
type SimulationState = (Int, Int, [Int], Int)

changeValInList list index newValue = take index list ++ [newValue] ++ drop (index + 1) list

solve_slow' :: (Int -> Int) -> State SimulationState Solution
solve_slow' rule =  do
    (stepsSoFar, position, board, length) <- get
    let valueAtPosition = board !! position
    let newPosition = position + valueAtPosition
    put (stepsSoFar + 1, newPosition, changeValInList board position $ rule valueAtPosition, length)
    if newPosition < 0 || newPosition >= length
        then return stepsSoFar
        else solve_slow' rule

solve_slow :: Rule -> [Int] -> Int
solve_slow rule instructions = evalState (solve_slow' rule) (1, 0, instructions, length instructions)


{-- Much much faster implementation using STUArray -}
solve_fast' :: Rule -> STUArray s Int Int -> Int -> Int -> Int -> ST s Solution
solve_fast' rule board length stepsSoFar position = do
    if position < 0 || position >= length
        then return stepsSoFar
        else do
            valueAtPosition <- readArray board position
            let newPosition = position + valueAtPosition
            let newValue = rule valueAtPosition :: Int
            writeArray board position newValue
            solve_fast' rule board length (stepsSoFar + 1) newPosition

solve_fast :: Rule -> [Int] -> Solution
solve_fast rule instructions = runST $ do
  let n = length instructions :: Int
  board <- newListArray (0, n) instructions :: ST s (STUArray s Int Int)
  solve_fast' rule board n 0 0

main = do
    content <- readFile "day_5.in"
    let instructions = map (\x -> read x :: Int) $ lines content
    {--
    putStrLn $ show $ solve_slow part_1_rule [0, 3, 0, 1, -3]
    putStrLn $ show $ solve_slow part_1_rule instructions
    putStrLn $ show $ solve_slow part_2_rule [0, 3, 0, 1, -3]
    putStrLn $ show $ solve_slow part_2_rule instructions
    --}

    --putStrLn $ show $ solve_fast part_1_rule [0, 3, 0, 1, -3]
    --putStrLn $ show $ solve_fast part_2_rule [0, 3, 0, 1, -3]
    --putStrLn $ show $ solve_fast part_1_rule instructions
    putStrLn $ show $ solve_fast part_2_rule instructions
