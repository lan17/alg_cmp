import Debug.Trace

hasDeadlock :: [[Int]] -> Bool

anyBool :: [Bool] -> Bool
anyBool [] = False
anyBool (x:xs) = if x then True else anyBool xs

dfs :: [[Int]] -> [Int] -> Int -> Bool
dfs connections visited i = if i `elem` visited then True else anyBool $ map (\x -> dfs connections (i:visited) x) $ connections !! i


--hasDeadlock connections | trace (show connections) False = undefined

hasDeadlock connections = anyBool $ map (\x -> dfs connections [] x) [0..n]
  where n = (length connections) - 1

-- hasDeadlock ([[1],[2],[3,4],[4],[0]])

main = do
  --let inputList = [[]]
  input <- readFile "isDeadlock.in"
  let inputList = read input :: [[Int]]
  putStrLn $ show $ hasDeadlock inputList