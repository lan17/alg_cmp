import Data.List (group, sort)
import Control.Monad (liftM2)

hist :: Ord a => [a] -> [(a, Int)]
-- hist = map (liftM2 (,) head length) . group . sort
hist = map (\x -> (head x, length x)) . group . sort