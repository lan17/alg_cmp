import GCJ

isTidy :: [Char] -> Bool
isTidy x = all (\(x,y) -> x <= y) $ zip x $ tail x

findTidy nStr = nStr

solve nStr = if isTidy nStr then nStr else tidy
    where tidy = findTidy nStr

main = gcjMain solve
