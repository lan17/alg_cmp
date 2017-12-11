import Control.Monad.ST
import Data.Array.ST
import Data.Foldable
import Control.Monad

-- wiki-copied code starts here
partition arr left right pivotIndex = do
    pivotValue <- readArray arr pivotIndex
    swap arr pivotIndex right
    storeIndex <- foreachWith [left..right-1] left (\i storeIndex -> do
        val <- readArray arr i
        if (val <= pivotValue)
            then do
                 swap arr i storeIndex
                 return (storeIndex + 1)
            else do
                 return storeIndex )
    swap arr storeIndex right
    return storeIndex

qsort arr left right = when (right > left) $ do
    let pivotIndex = left + ((right-left) `div` 2)
    newPivot <- partition arr left right pivotIndex

    qsort arr left (newPivot - 1)
    qsort arr (newPivot + 1) right

-- wrapper to sort a list as an array
sortList xs = runST $ do
    let lastIndex = length xs - 1
    arr <- newListArray (0,lastIndex) xs :: ST s (STUArray s Int Int)
    qsort arr 0 lastIndex
    newXs <- getElems arr
    return newXs

-- test example
main = print $ sortList [212498,127,5981,2749812,74879,126,4,51,2412]

-- helpers
swap arr left right = do
    leftVal <- readArray arr left
    rightVal <- readArray arr right
    writeArray arr left rightVal
    writeArray arr right leftVal

-- foreachWith takes a list, and a value that can be modified by the function, and
-- it returns the modified value after mapping the function over the list.
foreachWith xs v f = foldlM (flip f) v xs