import Data.List
import Control.Monad.State

changeValInList list index newValue = take index list ++ [newValue] ++ drop (index + 1) list

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

solve :: (Int -> Int) -> [Int] -> Int
solve rule instructions = evalState (simulate rule) (1, 0, instructions, length instructions)

main = do
    content <- readFile "day_5.in"
    let instructions = map (\x -> read x :: Int) $ lines content
    putStrLn $ show $ solve part_1_rule [0, 3, 0, 1, -3]
    putStrLn $ show $ solve part_1_rule instructions

    putStrLn $ show $ solve part_2_rule [0, 3, 0, 1, -3]
    putStrLn $ show $ solve part_2_rule instructions
