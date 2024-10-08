#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[20];
    int cantidad;
    float precio;
}producto;

void getProducto(producto array[], int n);
void ordMontoInsercion(producto array[], int n);

int main()
{   
    int n;
    printf("Ingrese el numero de productos: ");
    scanf("%d", &n);

    producto array[n];

    getProducto(array,n);

    ordMontoInsercion(array,n);

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

void ordMontoInsercion(producto array[], int n)
{
    int i,j;
    producto aux;
    for(i = 1; i < n; i++)
    {
        j = i;
        aux = array[i];
        while(j > 0 && (aux.cantidad * aux.precio < array[j - 1].cantidad * array[j - 1].precio))
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
}
