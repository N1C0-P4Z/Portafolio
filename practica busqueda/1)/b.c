#include <stdio.h>
#include <stdlib.h>

int busquedaSecuencial(float array[], int n, int clave);

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

    float clave;
    printf("Ingrese el numero a buscar: ");
    scanf("%f", &clave);

    int esta = busquedaSecuencial(array,n,clave);

    if(esta == -1)
        printf("El numero %f no esta en el arreglo\n", clave);
    else
        printf("El numero %f si esta en la lista\n", clave);
    

    return 0;
}

int busquedaSecuencial(float array[], int n, int clave)
{
    for(int i = 0; i < n; i++){
        if(clave == array[i])
            return 1;
    }
    return -1;
}
