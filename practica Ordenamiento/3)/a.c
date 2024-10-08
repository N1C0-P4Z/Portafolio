#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[20];
    int cantidad;
    float precio;
}producto;

void getProducto(producto array[], int n);
void ordMontoBurbuja(producto array[], int n);

int main()
{   
    int n;
    printf("Ingrese el numero de productos: ");
    scanf("%d", &n);

    producto array[n];

    getProducto(array,n);

    ordMontoBurbuja(array,n);

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

void ordMontoBurbuja(producto array[], int n)
{
    int i,j,indiceIntercambio;
    producto aux;

    i = n-1;
    while(i > 0){
        indiceIntercambio = 0;
        for(j = 0; j < i; j++)
            if((array[j].cantidad * array[j].precio) > (array[j + 1].cantidad * array[j + 1].precio)){
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                indiceIntercambio = j;
            }
        i = indiceIntercambio;   
    }
}
