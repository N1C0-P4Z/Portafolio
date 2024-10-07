#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main()
{   
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("El factorial de %d es %d\n", n, factorial(n));
    return 0;
}
int factorial(int n)
{
    if(n == 0 )
        return 1;
    else
        return n * factorial(n -1);
}

#include <stdio.h>
#include <stdlib.h>
int sumaNenteros(int n);

int main()
{   
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("La suma de los primeros %d enteros es %d\n", n, sumaNenteros(n));

    return 0;
}

int sumaNenteros(int n)
{   
    if(n == 1)
        return 1;
    else
        return n + sumaNenteros(n-1);
}

#include <stdio.h>
#include <stdlib.h>

int sumaPares(int n);

int main()
{   
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("La suma de los numeros pares de %d es %d\n",n,sumaPares(n));

    return 0;
}

int sumaPares(int n)
{   
    if(n < 2)
        return 0;
    if(n % 2 == 0){
        return n + sumaPares(n-2);
    }else{
        return sumaPares(n-1);
    }
}

#include <stdio.h>
#include <stdlib.h>

float multiplicarArreglo(float array[], int n);

int main()
{   
    int n;
    printf("Ingrese el numero de elementos del arreglo: ");
    scanf("%d", &n);

    float array[n];
    for(int i = 0; i<n; i++){
        printf("Ingrese el numero %d: ",i);
        scanf("%f", &array[i]);
    }

    printf("La multiplicacion de los elementos del arreglo es %.2f\n", multiplicarArreglo(array,n));

    return 0;
}

float multiplicarArreglo(float array[], int n)
{   
    if(n == 0)
        return 1.0;
    else   
        return array[0] * multiplicarArreglo(array + 1, n -1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invertirArray(char array[], int inicio, int final);

int main()
{   
    char array[200];
    printf("Ingrese la frase: ");
    scanf("%[^\n]", &array);

    int n = strlen(array);
    invertirArray(array, 0, n-1);
    printf("La frase invertida es %s\n", array);
    return 0; 
}

void invertirArray(char array[], int inicio, int final)
{   
    if(inicio < final){
        char aux = array[inicio];
        array[inicio] = array[final];
        array[final] = aux;
        invertirArray(array, inicio + 1, final - 1);
    }
}
