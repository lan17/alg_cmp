doubleShit x = x + x
fac 0 = 1
fac n = n * fac(n-1)
powlist 0 = [1]
powlist n = 2 * head( s ) : s where s = powlist(n-1)
plf n = [2**x | x <- [1..n]]

main = print $ fac 5
