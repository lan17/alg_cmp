
hash :: [Integer] -> Integer -> Integer
hash xs l = sum $ map (\(val, index) -> val + 10 ^ index) (zip xs [1..l])

solve :: [Integer] -> Integer
solve memoryList = runST $ do
    let n = length memoryList


main = do
    content <- readFile "day_6.in"
    let memory = map (\x -> read x :: Integer) $ words content
    putStrLn $ show memory
