import Data.List

canDo :: Integral a => [a] -> a -> a -> Bool
canDo array step l = length (array `intersect` [0, step..(l)]) == 0

avoidObstacles :: Integral a => [a] -> a
avoidObstacles inputArray = minimum $ (map (\x -> if (canDo sorted x l) then x else l * l) [1..l])
    where
        sorted = sort inputArray
        l = last sorted