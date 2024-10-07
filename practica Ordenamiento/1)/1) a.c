#include <stdio.h>
#include <stdlib.h>

void ordBurbuja1(float array[],int n);

int main()
{   
    int n;
    printf("Ingrese un numero: ");
    scanf("%d",&n);

    float array[n];
    for(int i = 0; i < n; i++){
        printf("Ingrese el valor %d: ",i);
        scanf("%f", &array[i]);
    }

    ordBurbuja1(array,n);

    printf("La lista ordenada\n");
    for(int i=0; i<n;i++)
        printf("%.2f ", array[i]);
    printf("\n");

    return 0;
}

void ordBurbuja1(float array[], int n)
{
    int i,j;
    int indiceIntercambio;
    float aux;

    i=n-1;
    while(i>0)
    {
        indiceIntercambio=0;
        for(j = 0; j < i; j++)
            if(array[j + 1] < array[j]){
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                indiceIntercambio = j;
            }
        i = indiceIntercambio;
    }
}