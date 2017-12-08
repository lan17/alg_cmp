import Data.List
import Control.Monad.State

changeValInList list index newValue = take index list ++ [newValue] ++ drop (index + 1) list

type Solution = Int
type SimulationState = (Int, Int, [Int], Int)

simulate :: State SimulationState Solution
simulate =  do
    (stepsSoFar, position, board, length) <- get
    let valueAtPosition = board !! position
    let newPosition = position + valueAtPosition
    put (stepsSoFar + 1, newPosition, changeValInList board position (valueAtPosition + 1), length)
    if newPosition < 0 || newPosition >= length
        then return stepsSoFar
        else simulate

solve instructions = evalState simulate (1, 0, instructions, length instructions)

main = do
    content <- readFile "day_5.in"
    let instructions = map (\x -> read x :: Int) $ lines content
    putStrLn $ show $ solve [0, 3, 0, 1, -3]
    putStrLn $ show $ solve instructions
