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

