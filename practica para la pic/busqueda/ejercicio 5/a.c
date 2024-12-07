#include <stdio.h>
#include <stdlib.h>


void ordQUicksort(int array[], int primero, int ultimo);
int busquedaBin(int array[], int n, int clave);
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
        printf("Ingrese el numero [%d][%d]: ",f,c);
        scanf("%d", &array[i]);
    }

    ordQUicksort(array,0,nro - 1);

    int esta = busquedaBin(array,nro,-5);

    if(esta == -1)
        printf("El numero -5 no se encontra en la matriz");
    else    
        printf("El numero -5 si se encontro en la matriz");
    return 0;
}

void ordQUicksort(int array[], int primero, int ultimo)
{
    int i,j,central;
    int aux,pivot;

    central = (primero + ultimo)/2;
    pivot = array[central];

    i = primero;
    j = ultimo;

    do{
        while(array[i] < pivot)i++;
        while(array[j] > pivot)j--;

        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);

    if(primero < j)
        ordQUicksort(array,primero,j);
    if(i < ultimo)
        ordQUicksort(array,i,ultimo);
}

int busquedaBin(int array[], int n, int clave)
{
    int central,inicio,ultimo;
    int pivot;

    inicio = 0;
    ultimo = n-1;
    while(inicio <= ultimo){
        central = (inicio + ultimo/2);
        pivot = array[central];

        if(clave == pivot)
            return central;
        else if(clave < pivot)
            ultimo = central - 1;
            else
                inicio = central + 1;
    }
    return -1;
}