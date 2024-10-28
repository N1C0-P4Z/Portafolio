import Data.Char

doble :: Int -> Int
doble x = 2 * x

cuadrado :: Int -> Int
cuadrado x = x * x

dobleCuadrado :: Int -> Int
dobleCuadrado x = (doble . cuadrado) x

dobleCuadradoPar :: Int -> Bool
dobleCuadradoPar x = (even . dobleCuadrado) x 
--                 (even . doble . cuadrado) x 
                     
-- . :: (b -> c) -> (a -> b) -> (a -> c) El operador composion(.) devuelve una función.
--x.y = x(y( algo))

duplicar :: [a] -> [a]
duplicar [] = []
duplicar (x:xs) = x:x : duplicar xs

duplicarLargo :: [a] -> Int
duplicarLargo xs = (length . duplicar) xs

cuadradoLista :: [Int] -> [Int]
cuadradoLista xs = map cuadrado xs

filterOdd :: [Int] -> [Int]
filterOdd xs = filter odd xs

cuadradoImpares :: [Int] -> [Int]
cuadradoImpares xs = (cuadradoLista . filterOdd) xs

select :: [a] -> (a -> Bool) -> [a]
select xs f = (take 10 . filter f) xs

esVocal :: Char -> Bool
esVocal x = x `elem` "aeiouAEIOU"

cantidadVocal :: String -> Int
cantidadVocal xs = (length . filter esVocal) xs

contarBool :: [a] -> (a -> Bool) -> Int
contarBool xs f = (length . filter f) xs 

algunBool :: [a] -> (a -> Bool) -> Bool
algunBool xs f = (not . null . filter f) xs

todosBool :: [a] -> (a -> Bool) -> Bool
todosBool xs f = (null . filter (not . f))xs

-- 11) 

inversa :: [a] -> [a]
inversa [] = []
inversa (x:xs) = (inversa xs) ++ [x]

concatenarInvCad :: [[a]] -> [a]
concatenarInvCad xs = ((foldr (++) []) . (map inversa)) xs

-- 12)

max' :: [Int] -> Int
max' xs = foldr (\x y -> if(x > y) then x else y) minBound xs

concatenarMasLarga :: [String] -> [String]
concatenarMasLarga xs = let maxl = (max' . (map length)) xs
			in map (\x -> if(length x == maxl) then (map toUpper) x else x) xs
			
-- 13)

aplicarF :: Num c => (a -> b) -> (b -> Bool) -> (c -> b -> c) -> [a] -> c
aplicarF f g h xs = (foldl h 0 . filter g . map f) xs

--14)

fib' :: Int -> Int
fib' 0 = 0
fib' 1 = 1
fib' x = fib' (x - 1) + fib' (x - 2)

listaFib :: [Int]
listaFib = map fib' [1..]

primerosFib :: Int -> [Int]
primerosFib x = (take x . filter even) listaFib 

--15)

sinDuplicados :: [
