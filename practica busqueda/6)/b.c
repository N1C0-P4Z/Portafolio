#include <stdio.h>
#include <stdlib.h>

int busquedaSecuencial(int array[], int n, int clave);

int main()
{   
    int f,c,clave;

    printf("Ingrese el numero de filas: ");
    scanf("%d", &f);

    printf("Ingrese el numero de columnas: ");
    scanf("%d", &c);

    printf("Ingrese el numero a buscar: ");
    scanf("%d", &clave);

    int n, array[c], pos= 0;

    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++){
            printf("Ingrese el numero [%d][%d]: ",i,j);
            scanf("%d", &n);

            if(i == f - 1){
                array[pos] = n;
                pos++;
            }
        }
    

    int esta = busquedaSecuencial(array,c,clave);

    if(esta == -1)
        printf("El numero %d no esta en el arreglo\n", clave);
    else
        printf("El numero %d si esta en la lista\n", clave);
    

    return 0;
}



int busquedaSecuencial(int array[], int n, int clave)
{   
    for(int i = 0; i < n; i++){
        if(clave == array[i])
            return 1;
    }
    return -1;
}
