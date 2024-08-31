#include <stdio.h>
#include <stdlib.h>

void sumar10(int *arrayP[],int n);

int main()
{   
    int n;
    
    printf("Ingrese el numero de elementos: ");
    scanf("%d",&n);

    int array[n];
    int *arrayP[n];

    for(int i=0; i<n; i++){
        printf("Ingrese el elemento %d: ",i);
        scanf("%d", (array+i));
        *(arrayP + i) = (array + i);
    }

    sumar10(arrayP,n);
    for(int i= 0; i<n; i++){
        printf("%d\n", **(arrayP + i));
    }
    printf("\n");
    
    for(int i= 0; i<n; i++){
        printf("%d\n", *(array + i));
    }
    return 0;
}
void sumar10(int *arrayP[], int n)
{
    for(int i= 0; i<n; i++){
        **(arrayP+i) += 10; 
    }
}