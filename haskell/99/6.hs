import Control.Monad.ST
import Data.Array.ST

isPalindrome :: Eq a => [a] -> Bool
isPalindrome [] = True
isPalindrome (x:[]) = True
isPalindrome (x:xs) = if x /= (last xs) then False else isPalindrome $ take (n-1) xs
  where n = length xs
