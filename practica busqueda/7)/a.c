#include <stdio.h>
#include <stdlib.h>

void ordQuicksort(int array[], int inicio, int ultimo);
int busquedaBinaria(int array[], int n, int clave);

int main()
{   
    int f,c,clave;

    printf("Ingrese el numero de filas: ");
    scanf("%d", &f);

    printf("Ingrese el numero de columnas: ");
    scanf("%d", &c);

    printf("Ingrese el numero a buscar: ");
    scanf("%d", &clave);

    int n, array[c], pos= 0;

    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++){
            printf("Ingrese el numero [%d][%d]: ",i,j);
            scanf("%d", &n);

            if(!j){
                array[pos] = n;
                pos++;
            }
        }
    
    ordQuicksort(array,0,f-1);

    int esta = busquedaBinaria(array,c,clave);

    if(esta == -1)
        printf("El numero %d no esta en el arreglo\n", clave);
    else
        printf("El numero %d si esta en la lista\n", clave);
    

    return 0;
}

void ordQuicksort(int array[], int inicio, int ultimo)
{
    int i,j, central;
    int aux, pivot;

    central = (inicio + ultimo)/2;
    pivot = array[central];

    i = inicio;
    j = ultimo;

    do{
        while(array[i] < pivot) i++;
        while(array[j] > pivot) j--;

        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);

    if(inicio < j)
        ordQuicksort(array,inicio,j);
    if(i < ultimo)
        ordQuicksort(array, i, ultimo);
}

int busquedaBinaria(int array[], int n, int clave)
{   
    int central, inicio, ultimo;
    int pivot;

    inicio = 0;
    ultimo = n-1;

    while(inicio <= ultimo){
        central = (inicio + ultimo)/2;
        pivot = array[central];

        if(clave == pivot)
            return clave;
        else if(clave < pivot)
            ultimo = central - 1;
        else 
            inicio = central + 1;
    }
    return -1;
}
