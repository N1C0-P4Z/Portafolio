import Data.Char

map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f(x:xs) = f x:map' f xs

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' f (x:xs) = if f x then x:filter' f xs
			  else filter' f xs

foldr' :: (a -> b -> b) -> [a] -> b -> b
foldr' f [] k = k
foldr' f (x:xs) k = f x (foldr' f xs k)

sum' :: [Int] -> Int
sum' xs = foldr' (+) xs 0 

max' :: [Int] -> Int
max' xs = foldr' (\ x y -> if x<y then y else x) xs 0

min' :: [Int] -> Int
min' xs = foldr' (\x y -> if y<x then y else x ) xs maxBound

avg' :: [Float] -> Float
avg' xs = (foldr' (+) xs 0)/ fromIntegral(length xs)

odd' :: [Int] -> [Int]
odd' xs = filter' (\ x -> mod x 2 /= 0) xs 

even' :: [Int] -> [Int]
even' xs = filter' (\x -> mod x 2 == 0) xs

primeAux :: Int -> Bool
primeAux n
	|n < 2 = False
	|otherwise = null[x|x <-[2..(n-1)], mod n x ==0]
	
prime' :: [Int] -> [Int]
prime' xs =  filter' primeAux xs

notprimeAux :: Int -> Bool
notprimeAux n
	|n == 1 = False
	|primeAux n = False
	|otherwise = True
	
notprime' :: [Int] -> [Int]
notprime' xs = filter' notprimeAux xs

takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile' f (x:xs)
		|f x = x:takeWhile' f xs
		|otherwise = []
		
dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' _ [] = []
dropWhile' f (x:xs)
		|f x = dropWhile' f xs
		|otherwise = (x:xs)
		
sumOfMax' :: [[Int]] -> Int
sumOfMax' xs = sum'(map' max' xs)

sumOfMin' :: [[Int]] -> Int
sumOfMin' xs = sum'(map' min' xs)

yell :: String -> String
yell xs = map' toUpper xs

whisper :: String -> String
whisper xs = map' toLower xs

verTotal :: Int -> String
verTotal x
	|x > 0 = "Gano"
	|x == 0 = "Balance"
	|otherwise = "Perdio"
	
ganancia :: [Int] -> String
ganancia xs = let total = foldr' (+) xs 0
	      in verTotal total
	      
twice' :: (a -> a) -> a -> a
twice' f xs = f(f xs)

quicksort2 :: [Int] -> (Int -> Int -> Int) -> [Int]
quicksort2 [] _ = []
quicksort2 (x:xs) f = let men = filter'(\k -> f x k == -1) xs
			  may = filter'(\k -> f x k == 1) xs
			  iguales = filter'(\k -> f x k == 0) xs
		      in quicksort2 men f ++ quicksort2 iguales f ++ [x] ++ quicksort2 may f
		      
longitudes :: [String] -> [String]
longitudes [] = []
longitudes (x:xs) = let men = filter'(\k -> length k <= length x) xs
			may = filter'(\k -> length k > length x) xs
		
		    in longitudes men ++ [x] ++ longitudes may 
		    
--6)

precioPlato :: 

