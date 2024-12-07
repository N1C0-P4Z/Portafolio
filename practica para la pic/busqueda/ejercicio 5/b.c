#include <stdio.h>
#include <stdlib.h>


void ordSeleccion(int array[], int n);
int busquedaSecuencial(int array[], int n, int clave);

int main()
{
    int f,c;

    printf("ingrese la cantidad de filas: ");
    scanf("%d", &f);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &c);

    int nro = f * c;
    int array[nro];

    for(int i = 0; i < nro; i++){
        printf("Ingrese el numero [%d]: ",i);
        scanf("%d", &array[i]);
    }

    ordSeleccion(array,nro);

    int esta = busquedaSecuencial(array,nro,-5);

    if(esta == -1)
        printf("El numero -5 no se encontra en la matriz");
    else    
        printf("El numero -5 si se encontro en la matriz");
    return 0;
}
void ordSeleccion(int array[], int n)
{
    int i,j,indiceMenor;
    int aux;

    for(i = 0; i < n-1; i++){
        indiceMenor = i;
        for(j = i + 1; j < n; j++)
            if(array[j] < array[indiceMenor])
                indiceMenor = j;
        if(i != indiceMenor){
            aux = array[i];
            array[i] = array[indiceMenor];
            array[indiceMenor] = aux;
        }
    }
}
int busquedaSecuencial(int array[], int n, int clave)
{
    for(int i = 0; i < n; i++){
        if(clave == array[i])
            return 1;
    }
    return -1;
}