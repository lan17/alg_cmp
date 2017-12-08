import Data.List

validPhrase phrases = (length phrases) == length (reverse  $ nub $ reverse phrases)

solveIt listOfPhrases = sum $ map (\x -> if x then 1 else 0) $ map validPhrase listOfPhrases

main = do
    content <- readFile "day_4.in"
    let byWords = map words $ lines content
    let toInt = \x -> if x then 1 else 0
    let validNumPart1 = solveIt byWords
    let validNumPart2 = solveIt $ map (\x -> map sort x) byWords
    putStrLn $ show validNumPart1
    putStrLn $ show validNumPart2
