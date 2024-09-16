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

max' :: [Int] -> Int
max' xs = foldr' (\x y -> if (x > y) then x else y) xs 0

min' :: [Int] -> Int
min' xs = foldr' (\x y -> if (x < y) then x else y) xs maxBound

sum' :: [Int] -> Int
sum' xs = foldr' (+) xs 0
--5)

cerradurasAbiertas :: [Bool] -> Int
cerradurasAbiertas xs = length (filter'(\x -> x == True) xs)

todasCerradas :: [Bool] -> Bool
todasCerradas xs = length (filter'(\x -> x == True) xs) == 0

--7)
aprobados :: [Int] -> Int
aprobados xs = length(filter'(\x -> x >=6)xs)

promedioNotas :: [Int] -> Float
promedioNotas xs = let notasValidas = filter' (\x -> x /=0) xs
		   in if (length notasValidas == 0) then 0 else fromIntegral (sum' notasValidas)/fromIntegral (length notasValidas)
		   
--1)
proporcion3 :: [Int] -> Int -> Int -> Int -> Float
proporcion3 xs a b c = let total = length xs
			   goles = length(filter'(\x -> x ==a || x == b || x == c)xs)
		       in 
		           fromIntegral goles / fromIntegral total
		           
goles3 :: [Int] -> Int -> Int -> Int -> (Int,Int,Int)
goles3 xs a b c = let golesA = length(filter'(\x -> x == a)xs)
		      golesB = length(filter'(\x -> x == b)xs)
		      golesC = length(filter'(\x -> x == c)xs)
		  in 
		  	(golesA,golesB,golesC)
		  	
foldl' :: (b -> a -> b) -> [a] -> b -> b
foldl' _ [] k = k
foldl' f (x:xs) k = foldl' f xs (f k x)

takeWhile1 :: (a -> Bool) -> [a] -> [a]
takeWhile1 _ [] = []
takeWhile1 f (x:xs) 
		|f x = x:takeWhile1 f xs
		|otherwise = []
		
dropWhile1 :: (a -> Bool) -> [a] -> [a]
dropWhile1 _ [] = []
dropWhile1 f (x:xs) 
		|f x = dropWhile1 f xs
		|otherwise = x:xs
		
sumOfMax1 :: [[Int]] -> Int
sumOfMax1 xs = sum' (map' max' xs)

sumOfMin1 :: [[Int]] -> Int
sumOfMin1 xs = sum' (map' min' xs)

primeAux :: Int -> Bool
primeAux n 
	|n < 2 = False
	|otherwise = null[x|x <- [2..(n-1)], mod n x == 0]
	
prime' :: [Int] -> [Int]
prime' xs = filter' primeAux xs

notprimeAux :: Int -> Bool
notprimeAux n
	|n == 1 = False
	|primeAux n = False
	|otherwise = True
	
notprime' :: [Int] -> [Int]

gananciaAux :: Int -> String
gananciaAux x
	|x > 0 = "Gano"
	|x == 0 = "Balance"
	|x < 0 = "Perdio"
	
ganancia :: [Int] -> String
ganancia [] = error "Lista Vacia"
ganancia xs = let total = foldr' (+) xs 0
	      in  gananciaAux total
	      
	      
notprime' xs = filter' notprimeAux xs

		

