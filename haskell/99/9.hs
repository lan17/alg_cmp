import Data.List

pack :: Eq a => [a] -> [[a]]
pack xs = groupBy (==) xs

encode xs = map (\x -> (length x, head x)) $ pack xs

data Encoded a = Multiple Int a | Single a
  deriving Show

encode_11 :: Eq a => [a] -> [Encoded a]
encode_11 xs = map (\(count, el) -> if count == 1 then Single el else Multiple count el) $ encode xs

unpack :: Encoded a -> [a]
unpack (Single a) = [a]
unpack (Multiple c a) = replicate c a

decodeModified :: [Encoded a] -> [a]
decodeModified [] = []
decodeModified (x:xs) = unpack x ++ decodeModified xs