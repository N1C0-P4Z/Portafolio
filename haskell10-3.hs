cubo::Float -> Float
cubo x = x*x*x

menorValorTripla::(Int, Int, Int) -> Int
menorValorTripla (a, b, c) 
 | a<=b && a<=c = a
 | b<=a && b<=c = b
 | c<=a && c<=b = c
 
mayorValorTripla::(Int, Int, Int) -> Int
mayorValorTripla (a, b, c) 
 | a>=b && a>=c = a
 | b>=a && b>=c = b
 | c>=a && c>=b = c
                                                                                                     
tercerElemento::[a]->a
tercerElemento (a:b:c:xs) = c

inversoTupla::(a, b, c) -> (c,b,a)
inversoTupla (a, b, c) = (c,b,a) 

primerAlFinal::[a]->[a]
primerAlFinal (x:xs) = xs++[x]

parOrdenado::Int->Int->Int->(Int,Int)
parOrdenado a b c  = (menorValorTripla (a,b,c), mayorValorTripla (a,b,c))

tresOrdenado::Int->Int->Int->[Int]
tresOrdenado a b c = quicksort [a,b,c]

quicksort::[Int]->[Int]
quicksort [] = []
quicksort (x:xs) = let menores = quicksort [y | y<-xs, y<=x]
                       mayores = quicksort [y| y<-xs, y>x]
                       
                   in  menores ++ [x] ++ mayores

listasinsegundo::[a]->[a]
listasinsegundo (x:y:xs) = (x:xs)


sumaMayork::[Int]->Int->Bool
sumaMayork xs k = ((sum xs) > k)

factorial::Int->Int
factorial 0 = 1
factorial x = x*(factorial (x-1))
