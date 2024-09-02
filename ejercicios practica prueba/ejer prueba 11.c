#include <stdio.h>
#include <stdlib.h>

void print_array(int *p, int n);

int main()
{   
    int n;
    printf("Ingrese el numero de elementos del array: ");
    scanf("%d",&n);

    int array[n];

    for(int i=0; i<n; i++){
        printf("Ingrese el numero %d: ",i);
        scanf("%d", array + i);
    }
    printf("\n");

    print_array(array,n);

    return 0;
}

void print_array(int *p, int n)
{   int *ptr = p;
    for(int i=0; i<n; i++){
        printf("[%d]", *(p+i));
    }
}