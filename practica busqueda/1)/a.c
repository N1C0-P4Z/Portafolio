#include <stdio.h>
#include <stdlib.h>

void ordBurbuja(float array[], int n);
int busquedaBinaria(float array[], int n, int clave);

int main()
{   
    int n;
    printf("Ingrese la cantidad de elementos del array: ");
    scanf("%d", &n);

    float array[n];

    for(int i = 0; i < n; i++){
        printf("Ingrese el numero %d: ",i);
        scanf("%f", &array[i]);
    }

    ordBurbuja(array,n);

    float clave;
    printf("Ingrese el numero a buscar: ");
    scanf("%f", &clave);

    int esta = busquedaBinaria(array,n,clave);

    if(esta == -1)
        printf("El numero %f no esta en el arreglo\n", clave);
    else
        printf("El numero %f si esta en la lista\n", clave);
    

    return 0;
}

void ordBurbuja(float array[], int n)
{
    int i,j,indiceIntercambio;

    float aux;

    i = n-1;
    while(i > 0){
        indiceIntercambio = 0;
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

int busquedaBinaria(float array[], int n, int clave)
{   
    int central, inicio, ultimo;
    float pivot;

    inicio = 0;
    ultimo = n-1;

    while(inicio <= ultimo){
        central = (inicio + ultimo)/2;
        pivot = array[central];

        if(clave == pivot)
            return central;
        else if(clave < pivot)
                ultimo = central - 1;
        else
            inicio = central + 1; 
    }
    return -1;
}
