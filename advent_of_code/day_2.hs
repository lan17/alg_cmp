
part_1 matrix = sum $ map (\row -> (maximum row)  - (minimum row)) matrix

zip_combos row = map (\n -> zip row $ (drop n row) ++ (take n row)) [1..(l-1)]
    where l = length row
sum_zips z = map (\(a,b) -> if (max a b) `mod` (min a b) == 0 then a `div` b else 0) z
find_evenly_divisible_numbers row = sum $ map sum $ map sum_zips $ zip_combos row

part_2 matrix = sum $ map find_evenly_divisible_numbers matrix

main = do
    content <- readFile "day_2.in"
    let matrix = map (\x -> map (\y -> read y :: Integer) x) $ map words $ lines content
    putStrLn $ show $ part_1 matrix
    putStrLn $ show $ part_2 matrix

