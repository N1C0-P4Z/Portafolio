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

aux1 :: Int -> Int -> Int
aux1 x y 
	|y < x = -1
	|y == x = 0
	|y > x = 1
	
	
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
--3)
proporcion3::[Int]->Int->Int->Int->Float
proporcion3 xs a b c = let 
			total = length xs
			goles3 = length(filter' (\x -> x==a||x==b||x==c) xs)
			in fromIntegral goles3 / fromIntegral total
			
foldl' :: (b -> a -> a) -> [a] -> b -> b
foldl' _ [] k = k
foldl' f (x:xs) k = foldl' f xs ( f k x)
--6)

precioPlato :: String -> Int
precioPlato "Arroz con Pollo" = 3000
precioPlato "Carne con Papa" = 4000
precioPlato "Milanesas" = 2000
precioPlato "Hamburguesas" = 5000
precioPlato _ = 0

precioTotal :: [String] -> Int
precioTotal xs = sum'(map' precioPlato xs)

--7)

aprobados :: [Int] -> Int
aprobados xs = length(filter' (\xs -> xs >= 6)xs)

promedioNotas :: [Int] -> Float
promedioNotas xs = let notavalida = filter'(\ xs -> xs /= 0) xs
		   in if length notavalida == 0 then 0
		   		                else fromIntegral(sum' notavalida)/ fromIntegral(length notavalida)
		   		                
alfabeticamente :: [String] -> [String]
alfabeticamente [] = []
alfabeticamente (x:xs) = let men= [y |y <- xs, y < x]
			     may= [y |y <- xs, y >= x]
			     
			  in alfabeticamente men ++ [x] ++ alfabeticamente may
			  
maximo :: (String,Int) -> (String,Int) -> (String,Int)
maximo x y = if (snd x > snd y) then x else y

calcularDistancias :: [(String,Int)] -> [(String,Int)]
calcularDistancias [_] = []
calcularDistancias (a:b:xs) = (fst b,snd b - snd a): calcularDistancias (b:xs)
			
tomarDescanso :: [(String,Int)] -> String
tomarDescanso xs = fst(foldr' maximo (calcularDistancias xs)("",minBound))
			
cantPueblos :: [(String,Int)] -> Int -> Int
cantPueblos xs k = length(filter'(\x -> if(snd x <= 10*k) then True else False) xs)

--1) 
proporcion3 :: [Int] -> Int -> Int -> Int -> Float
proporcion3 xs a b c = let 
			   total = lenght xs
			   goles = lenght(filter'(\k -> k==a || k==b || k==c)xs)
			in fromIntegral goles / fromIntegral total
			
maximo :: (String,Int) -> (String,Int) -> (String,Int)
maximo x y = if (snd x > snd y) then x else ymaximo :: (String,Int) -> (String,Int) -> (String,Int)
maximo x y = if (snd x > snd y) then x else y  
