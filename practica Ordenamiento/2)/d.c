#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char array[][100], int primero, int ultimo);

int main()
{   
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    char array[n][100];
    for(int i=0; i<n; i++){
        printf("Ingrese el nombre %d: ",i);
        scanf("%s", array[i]);
    }

    quicksort(array,0, n-1);

    printf("La lista ordenada es\n");

    for(int i = 0; i < n; i++){
        printf("%s ", array[i]);
    }
    printf("\n");
    return 0;
}

void quicksort(char array[][100], int primero, int ultimo)
{
    int i,j,central;
    char pivot[100];

    central = (primero + ultimo)/2;
    strcpy(pivot, array[central]);

    i = primero;
    j = ultimo;

    do{
        while(strcmp(array[i],pivot)<0) i++;
        while(strcmp(array[j], pivot)>0) j--;

        if(i <= j){
            char aux[100];
            strcpy(aux, array[i]);
            strcpy(array[i], array[j]);
            strcpy(array[j], aux);
            i++;
            j--;
        }
    }while(i <= j);
    if(primero < j)
        quicksort(array, primero, j);
    if(i < ultimo)
        quicksort(array, i, ultimo);
}
