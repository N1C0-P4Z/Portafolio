import Data.Char

--7)

esVocal :: Char -> Bool
esVocal c = c `elem` "aeiouAEIOU"

cantVocales :: String -> Int
cantVocales xs = (length . filter esVocal) xs

--8)

cantidadBool :: [a] -> (a -> Bool) -> Int
cantidadBool xs f = (length . filter f) xs

--9)

algunaBool :: [a] -> (a -> Bool) -> Bool
algunaBool xs f = (not . null . filter f) xs

--10)

todosBool :: [a] -> (a -> Bool) -> Bool
todosBool xs f = (null . filter(not . f)) xs

--11)

inversa :: [a] -> [a]
inversa [] = []
inversa (x:xs) = inversa xs ++ [x]

concatenarInv :: [[a]] -> [a]
concatenarInv xs = ((foldl (++) []) . (map inversa)) xs

--12)

max' :: [Int] -> Int
max' xs = foldl (\x y -> if(x > y) then x else y) minBound xs

concatenarMasLarga :: [String] -> [String]
concatenarMasLarga xs = let maxL = (max' . (map length)) xs
			in map (\x -> if(length x == maxL) then (map toUpper) x else x) xs
			
--13)

aplicarF :: Num c => (a -> b) -> (b -> Bool) -> (c -> b -> c) -> [a] -> c
aplicarF f g h xs = (foldl h 0 . filter g . map f) xs

--14)

fib' :: Int -> Int
fib' 0 = 0
fib' 1 = 1
fib' x = fib'(x - 1) + fib'(x - 2)

listaFib :: [Int]
listaFib = map fib' [1..]

aplicarnFib :: Int -> [Int]
aplicarnFib x = (take x . filter even) listaFib

--Practica Tipos de Datos Algebraicos

data Figura = Circ Float Float Float |
	      Rect Float Float Float Float deriving (Show)

area' :: Figura -> Float
area' (Circ _ _ r) = 3.14 * r * r
area' (Rect x1 y1 x2 y2) = abs(x2 - x1) * abs(y2 - y1)

data Semaforo = Rojo | Amarillo | Verde deriving Show

cambiarSemaforo :: Semaforo -> Semaforo
cambiarSemaforo Rojo = Verde
cambiarSemaforo Verde = Amarillo
cambiarSemaforo Amarillo = Rojo



