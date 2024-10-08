#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[20];
    int cantidad;
    float precio;
}producto;

void getProducto(producto array[], int n);
void ordMontoQuicksort(producto array[], int primero, int ultimo);

int main()
{   
    int n;
    printf("Ingrese el numero de productos: ");
    scanf("%d", &n);

    producto array[n];

    getProducto(array,n);

    ordMontoQuicksort(array,0,n-1);

    printf("El arreglo ordenado es:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i].nombre);
        printf("%d\n", array[i].cantidad);
        printf("%.2f\n", array[i].precio);
        printf("\n");
    }
    return 0;
}
void getProducto(producto array[], int n)
{
    for(int i = 0; i < n; i++){
        getchar();
        printf("Ingrese el nombre del producto %d: ",i);
        scanf("%s", array[i].nombre);
        printf("Ingrese la cantidad del producto %d: ",i);
        scanf("%d", &array[i].cantidad);
        printf("Ingrese el precio del producto %d: ",i);
        scanf("%f", &array[i].precio);
        printf("\n");
    }
}

void ordMontoQuicksort(producto array[], int primero, int ultimo)
{
    int i,j,central;
    producto pivot, aux;

    central = (primero + ultimo)/2;
    pivot = array[central];
    do{
        while (array[i].cantidad * array[i].precio < pivot.cantidad * pivot.precio) i++;
        while (array[j].cantidad * array[j].precio > pivot.cantidad * pivot.precio) j--;

        if(i <= j)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }while (i <= j);

    if (primero < j)
        ordMontoQuicksort(array,primero,j);
    if(i < ultimo)
        ordMontoQuicksort(array, i, ultimo);
}
