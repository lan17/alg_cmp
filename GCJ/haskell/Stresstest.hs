{-# LANGUAGE BangPatterns #-}
import GCJ

import Data.Maybe
import Criterion.Measurement
import Control.Parallel.Strategies
import Control.Parallel
import Control.DeepSeq

--stress x = show $ answer (read x :: Int)

isPrime x = foldl (&&) True $ map (\d -> x `mod` d == 0) [2..x-1]

stress x = show $ isPrime n
    where n = read x :: Integer


main = gcjMain stress
