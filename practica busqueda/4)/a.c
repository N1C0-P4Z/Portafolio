#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordQuicksort(char array[][100], int primero, int ultimo);
int busquedaBinaria(char array[][100], int n, char clave[]);

int main()
{   
    int n;
    printf("Ingrese el numero de nombres: ");
    scanf("%d", &n);

    char array[n][100];
    for(int i = 0; i < n; i++){
        printf("Ingrese el nombre %d: ",i);
        scanf("%s", array[i]);
    }
    
    ordQuicksort(array,0,n-1);
    
    int esta = busquedaBinaria(array,n,"Hugo");

    if(esta == -1)
        printf("El nombre 'Hugo' no se encuentra en la lista");
    else
        printf("El nombre 'Hugo' esta en la lista");

    return 0;
}

void ordQuicksort(char array[][100], int primero, int ultimo)
{
    int i,j,central;
    char pivot[100],aux[100];

    central = (primero + ultimo)/2;
    strcpy(pivot, array[central]);

    i = primero;
    j = ultimo;

    do{
        while(strcmp(array[i], pivot) < 0) i++;
        while(strcmp(array[j], pivot) > 0) j--;

        if(i <= j){
            strcpy(aux, array[i]);
            strcpy(array[i], array[j]);
            strcpy(array[j], aux);
            i++;
            j--;
        }
    }while(i <= j);

    if(primero < j)
        ordQuicksort(array, primero, j);
    if(i < ultimo)
        ordQuicksort(array, i, ultimo);
}

int busquedaBinaria(char array[][100], int n, char clave[])
{   
    int central, inicio, ultimo;
    char pivot[100];

    inicio = 0;
    ultimo = n-1;

    while(inicio <= ultimo){
        central = (inicio + ultimo)/2;
        strcpy(pivot ,array[central]);

        if(strcmp(clave, pivot) == 0)
            return central;
        else if(strcmp(clave, pivot) < 0)
                ultimo = central - 1;
        else 
            inicio = central + 1;
    }
    return -1;
}


