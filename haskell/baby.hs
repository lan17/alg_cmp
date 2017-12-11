doubleShit x = x + x
fac 0 = 1
fac n = n * fac(n-1)
powlist 0 = [1]
powlist n = 2 * head( s ) : s where s = powlist(n-1)
plf n = [2**x | x <- [1..n]]
digits :: Integer -> [Integer]
digits 0 = []
digits x = (x `mod` 10) : (digits $ x `div` 10)

isLucky n = firstHalf == secondHalf where
        digitList = digits n
        nn = length (digitList) `div` 2
        firstHalf = sum (take nn digitList)
        secondHalf = sum (drop nn digitList)


initials :: String -> String -> String
initials (f:_) (l:_)= [f] ++ ", " ++ [l]

quicksort [] = []
quicksort (x:xs) =
    let smallerSorted = quicksort [a | a <- xs, a <= x]
        biggerSorted = quicksort [a | a <- xs, a > x]
    in  smallerSorted ++ [x] ++ biggerSorted

{-|
merge :: (Ord a) => [a] -> [a] -> [a]
merge x [] = x
merge [] y = y
merge xx@(x:xs) yy@(y:ys) = if x < y then x:(merge xs yy) else y:(merge ys xx)

mergesort :: (Ord a) => [a] -> [a]
mergesort xs = merge
-}

sortByHeight a =
        let people = quicksort $ filter (/= -1) a
            replacePeople [] _ = []
            replacePeople _ [] = []
            replacePeople (x:xs) yy@(y:ys) = if x == -1 then x : (replacePeople xs yy) else y : (replacePeople xs ys)
        in replacePeople a people

main = do
  print $ fac 5
  print (initials "Lev" "Neiman")
  print (quicksort "FUCK YOU AND SHIT")
  print $ sortByHeight [-1, 150, 190, 170, -1, -1, 160, 180]

