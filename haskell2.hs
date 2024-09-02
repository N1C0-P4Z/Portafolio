
import Data.Char

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
min' xs = foldr' minaux xs maxBound

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
    |otherwise = null [x|x <-[2.. (n-1)], mod n x == 0]

notprimeaux :: Int -> Bool
notprimeaux n
    |primeaux n = False
    |otherwise = True

prime' :: [Int] -> [Int]
prime' xs = filter' primeaux  xs 

notprime' :: [Int] -> [Int]
notprime' xs = filter' notprimeaux xs

takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile' f (x:xs)
            |f x = x:takeWhile' f xs
            |otherwise = []

--funciones lamda o funciones anonimas, no hace falta definir una funcion aux, sino que defino una funcion chiquitita para una funcion en especifico

--minBound es el entero mas chico posible. Puedo usar 0 
--maxBound es el entero mas grando posible

max2' :: [Int] -> Int
max2' xs = foldr' (\ x y -> if x<y then y else x) xs minBound 
   
dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' _ [] = []
dropWhile' f (x:xs) 
            |f x =dropWhile' f xs
            |otherwise = x:xs
            
sumOfMax' :: [[Int]] -> Int
sumOfMax' xs = sum'(map max' xs)

sumOfMin' :: [[Int]] -> Int
sumOfMin' xs = sum' (map min' xs)

sums :: ([Int] -> Int) -> [[Int]] -> Int
sums m xs = sum' (map m xs)

yell' :: String -> String
yell' xs = map toUpper xs 

whisper :: String -> String
whisper xs = map toLower xs


evaluarTotal :: Int -> String
evaluarTotal x
            |x > 0 = "gano"
            |x == 0 = "Balance"
            |otherwise ="Perdio"
            
ganancia :: [Int] -> String
ganancia xs = 
            let total = foldr' (+) xs 0
            in evaluarTotal total
--            in if(total > 0) then "Gano"
--                             else if(total == 0) then "Balance"
--                                                 else "Perdio"
                  
                               
twice :: (a -> a) -> a -> a
twice f xs = f(f xs)

--ordenamiento
--cuanto tiempo demoro en ordenar quicksort: el mejor algoritmo de ordenamiento en casos generales. El mas rapidos

--valor cualquiera de la lista que vamos a llamar pibot. A la derecha vamos a poner todos los mayores a pibot y a la Izquierda todos los menores a pibot.

--quicksort'              quicksort' Los ordenamos(llamado recursivo)

--ePivot ++ [Pibot] ++ Dpivot


quicksort' :: [Int] -> [Int]
quicksort' [] = []
quicksort' (x:xs) = let men= [k|k <-xs, k<=x]
                        may= [k|k <-xs, k> x]
                    in (quicksort' men) ++ [x] ++ (quicksort' may)
                    
longitudes :: [String] -> [String]
longitudes
