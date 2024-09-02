#include <stdio.h>
#include <stdlib.h>

void cargarArrPuntReves( int array[], int *array2[], int n);

int main()
{   
    int n;

    printf("Ingrese el numero de elementos del arreglo: ");
    scanf("%d", &n);

    int array[n]; 

    for(int i=0; i<n; i++){
        printf("Ingrese el numero %d: ",i);
        scanf("%d", (array + i));
    }

    int *array2[n];
    cargarArrPuntReves(array,array2,n);
    
    for(int i=0; i<n; i++){
        printf("[%d]\n", **(array2 + i));
    }
    return 0;
}

void cargarArrPuntReves(int array[], int *array2[], int n)
{
    int aux = n-1;
    for(int i=0; i<n; aux--){
        *(array2 + aux) = (array + i);
    }
}
