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


main = print $ fac 5
