
fgeneral :: (a->b) -> [a] -> [b]
fgeneral _ [] = []
fgeneral y (x:xs) = y x : fgeneral y xs

filter':: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' f (x:xs) = if f x then x:filter' f xs
                          else filter' f xs

foldr' :: (a -> b -> b) -> [a] -> b -> b
foldr' f [] k = k
foldr' f (x:xs) k = f x (foldr' f xs k)

sum' :: [Int] -> Int
sum' xs = foldr' (+) xs 0

maxaux :: Int -> Int -> Int
maxaux x y = if x>y then x
                      else y

max' :: [Int] -> Int
max' xs = foldr' maxaux xs 0

minaux :: Int -> Int -> Int
minaux x y = if x<y then x
                      else y

min' :: [Int] -> Int
min' xs = foldr' minaux xs 2147483647

avg' :: [Float] -> Float
avg' xs = sum xs/(fromIntegral (length xs))

oddaux :: Int -> Bool
oddaux x = mod x 2 /= 0

odd' :: [Int] -> [Int]
odd' xs = filter' oddaux xs

evenaux :: Int -> Bool
evenaux x = mod x 2 == 0

even' :: [Int] -> [Int]
even' xs = filter' evenaux xs

primeaux :: Int -> Bool
primeaux n
    |n < 2 = False
    |otherwise = null [x|x <- [2.. (n-1)], mod x n == 0]

prime' :: [Int] -> [Int]
prime' xs = filter primeaux  xs 



