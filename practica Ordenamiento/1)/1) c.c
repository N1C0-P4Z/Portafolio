#include <stdio.h>
#include <stdlib.h>

void ordSeleccion (float a[], int n);

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

    ordSeleccion(array, n);

    printf("La lista ordenada es\n");
    for(int i = 0; i < n; i++){
        printf("%.2f ", array[i]);
    }
    printf("\n");
    
    return 0;
}
void ordSeleccion (float array[], int n)
{
    int indiceMenor, i ,j;

    for(i=0; i< n-1 ; i++)
    {
        indiceMenor = i;
        for(j = i + 1; j < n; j++)
        {
            if(array[j] < array[indiceMenor])
                indiceMenor = j;
        }
        if(i != indiceMenor)
        {
            float aux = array[i];
            array[i] = array[indiceMenor];
            array[indiceMenor] = aux;
        }
    }
}