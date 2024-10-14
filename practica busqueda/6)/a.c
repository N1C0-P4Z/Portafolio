#include <stdio.h>
#include <stdlib.h>

void ordBurbuja(int array[], int n);
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

            if(i == f - 1){
                array[pos] = n;
                pos++;
            }
        }
    
    ordBurbuja(array,c);

    int esta = busquedaBinaria(array,c,clave);

    if(esta == -1)
        printf("El numero %d no esta en el arreglo\n", clave);
    else
        printf("El numero %d si esta en la lista\n", clave);
    

    return 0;
}

void ordBurbuja(int array[], int n)
{
    int i,j,indiceIntercambio;
    int aux;

    i = n-1;
    while(i > 0){
        indiceIntercambio = 0;
        for(j = 0; j < i; j++)
            if(array[j - 1] < array[j]){
                aux = array[j - 1];
                array[j - 1] = array[indiceIntercambio];
                array[indiceIntercambio] = aux;
                indiceIntercambio = j;
            }
            i = indiceIntercambio;
    }
}

int busquedaBinaria(int array[], int n, int clave)
{   
    int central,inicio,ultimo;
    int pivot;

    inicio = 0;
    ultimo = n - 1;

    while(inicio <= ultimo){
        central = (inicio + ultimo)/2;
        pivot = array[central];

        if(clave == pivot)
            return clave;
        else if (clave < pivot)
            ultimo = central - 1;
        else 
            inicio = central + 1;
    }
    return -1;
}
