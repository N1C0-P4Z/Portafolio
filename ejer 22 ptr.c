#include <stdio.h>
#include <stdlib.h>

void cargaArrPuntReves(int array[], int *arrayP[], int n);

int main()
{   
    int n;

    printf("Ingrese el numero de elementos: ");
    scanf("%d",&n);

    int array[n];

    for(int i=0 ; i<n; i++){
        printf("Ingrese el numero %d: ",i);
        scanf("%d", array+i);
    }

    printf("\n");
    
    int *arrayP[n];
    cargaArrPuntReves(array,arrayP,n);

    for(int i=0; i<n; i++){
        printf("%d\n", **(arrayP + i));
    }
    return 0;
}

void cargaArrPuntReves(int array[], int *arrayP[], int n)
{
    int aux = n-1;
    for(int i=0; i<n; i++, aux--){
        *(arrayP + aux) = (array + i);
    }
}
