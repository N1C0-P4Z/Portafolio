import Data.Char

doble :: Int -> Int
doble x = 2*x

cuadrado :: Int -> Int
cuadrado x = x^2

doblecuadrado :: Int -> Int
doblecuadrado x = (doble . cuadrado)  x

doblecuadradoPar :: Int -> Bool
doblecuadradoPar x = (even . doblecuadrado) x

--3)
dobleLargo :: [a] -> Int
dobleLargo xs = (doble . length) xs
--4)

duplicar :: [a] -> [a]
duplicar [] = []
duplicar (x:xs) = x:x : duplicar xs

duplicarLargo :: [a] -> Int
duplicarLargo xs = (length . duplicar) xs

--5)
cuadradoImpares :: [Int] -> [Int]
cuadradoImpares xs = (map cuadrado . filter odd) xs

--6)

filtrar10primeros :: [a] -> (a -> Bool) -> [a]
filtrar10primeros xs f = take 10 . filter f $ xs

--7) 

esVocal :: Char -> Bool
esVocal c =  c `elem` "aeiouAEIOU"

cantidadVocales :: String -> Int
cantidadVocales = length . filter esVocal

--8)
cantidadquesatisfacen :: [a] -> (a -> Bool) -> Int
cantidadquesatisfacen xs f = (length . filter f) xs

--9) 

algunBool :: [a] -> (a -> Bool) -> Bool
algunBool xs f = (not . null . filter f) xs

--10)

todosBool :: [a] -> (a -> Bool) -> Bool
todosBool xs f = (null . filter (not . f)) xs

--11)

inversa :: [a] -> [a]
inversa [] = []
inversa (x:xs) = inversa xs ++ [x]

concatenarInvCad :: [[a]] -> [a]
concatenarInvCad xs = ((foldr (++) []) . (map inversa)) xs

--12)

max' :: [Int] -> Int
max' xs = foldr (\x y -> if(x > y) then x else y) minBound xs 

concatenarMasLarga :: [String] -> [String]
concatenarMasLarga xs = let maxL = max' . map length $ xs
			in map (\x -> if(length x == maxL) then (map toUpper) x else x) xs
			
--13)

aplicarF :: Num c => (a -> b) -> (b -> Bool) -> (c -> b -> c) -> [a] -> c
aplicarF f g h xs = foldl h 0 . filter g . map f $ xs

--14) 

fib' :: Int -> Int
fib' 0 = 0
fib' 1 = 1
fib' x = fib' (x - 1) + fib' (x - 2)

primerosFib :: Int -> [Int]
primerosFib x = take x . filter even $ map fib' [1..]


