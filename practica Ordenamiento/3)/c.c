#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[20];
    int cantidad;
    float precio;
}producto;

void getProducto(producto array[], int n);
void ordMontoSeleccion(producto array[], int n);

int main()
{   
    int n;
    printf("Ingrese el numero de productos: ");
    scanf("%d", &n);

    producto array[n];

    getProducto(array,n);

    ordMontoSeleccion(array,n);

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

void ordMontoSeleccion(producto array[], int n)
{
    int i,j,indiceMenor;
    producto aux;

    for(i = 0; i < n-1; i++)
    {
        indiceMenor = i;
        for(j = i + 1; j < n; j++)
        {
            if((array[j].cantidad * array[j].precio) < (array[indiceMenor].cantidad * array[indiceMenor].precio))
                indiceMenor = j;
            if(i != indiceMenor)
            {
                aux = array[i];
                array[i] = array[indiceMenor];
                array[indiceMenor] = aux;
            }
        }
    }
}