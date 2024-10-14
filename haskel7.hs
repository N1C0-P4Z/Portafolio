data Figura = Circ Punto Float |
              Rect Punto Punto 
              
data Punto = Punto Float Float

area :: Figura -> Float
area (Circ (Punto x y) r) = 3.14 * r * r
area (Rect (Punto x1 y1) (Punto x2 y2)) = abs(x2 - x1) * abs(y2 - y1)

data Semaforo = Rojo | Amarillo | Verde deriving Show

cambiarSemaforo :: Semaforo -> Semaforo
cambiarSemaforo Rojo = Verde
cambiarSemaforo Verde = Amarillo
cambiarSemaforo Amarillo = Rojo

data Expc = Valor Int | Suma Expc Expc

eval :: Expc -> Int
eval(Valor n) = n
eval(Suma e1 e2) = let v1 = Eval e1
                       v2 = Eval e2
                   in v1 + v2
                   
                   
data Expr2 a = Valor a |Suma (Expr2 a) (Expr2 a)

Eval1 :: Expr2 a -> a
Eval1(Valor n) = n
Eval1(Suma e1 e2) = let v1 = Eval e1
                        v2 = EVal e2
                    in v1 + v2
