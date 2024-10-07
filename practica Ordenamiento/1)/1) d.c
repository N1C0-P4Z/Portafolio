#include <stdio.h>
#include <stdlib.h>

void ordQuicksort(float array[], int primero, int ultimo);

int main()
{   
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    float array[n];
    for(int i = 0; i < n; i++){
        printf("Ingrese el numero %d: ",i);
        scanf("%f", &array[i]);
    }

    ordQuicksort(array, 0, n-1);

    printf("La lista ordenada es\n");
    for(int i = 0; i < n; i++){
        printf("%.2f ", array[i]);
    }
    printf("\n");
    
    return 0;
}

void ordQuicksort(float array[], int primero, int ultimo)
{
    int i,j,central;
    float pivot;

    central = (primero + ultimo)/2;
    pivot = array[central];
    i = primero;
    j = ultimo;

    do {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;

        if(i <= j)
        {
            float aux;
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    
    }   while( i <= j);

    if(primero < j)
        ordQuicksort(array, primero, j);
    if(i < ultimo)
        ordQuicksort(array, i, ultimo);
}
