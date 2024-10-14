#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int DNI[10];
    char nombre[30];
    char apellido[20];
    char sexo;
    int edad;
    int celular[20];
} cliente;

typedef struct
{
    float precio;
    int idProducto;
    cliente cli;
}compra;

void getCliente(compra array[], int n);
int buscarCliente(compra array[], int n, char nombre[], char sexo, float precioMin);
int main()
{
    int n;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &n);

    compra array[n];

    getCliente(array,n);
    
    char nombreBuscado[30] = "Hugo";
    char sexoBuscado = 'M';
    char precioMin = 100;

    int esta = buscarCliente(array,n,nombreBuscado,sexoBuscado,precioMin);

    if(esta == 1)
        printf("El cliente existe\n");
    else
        printf("El cliente no existe\n");
    
    return 0;
}

void getCliente(compra array[], int n)
{
    for(int i = 0; i < n; i++){
        printf("Ingrese el DNI del cliente %d: ",i);
        scanf("%d", &array[i].cli.DNI); 
        getchar();
        printf("Ingrese el nombre del cliente %d: ",i);
        scanf("%s", array[i].cli.nombre);
        getchar();
        printf("Ingrese el apellido del cliente %d: ",i);
        scanf("%s", array[i].cli.apellido);
        getchar();
        printf("Ingrese el sexo del cliente %d: ",i);
        scanf("%c", &array[i].cli.sexo);
        printf("Ingrese la edad del cliente %d: ",i);
        scanf("%d", &array[i].cli.edad);
        printf("Ingrese el numero de telefono del cliente %d: ",i);
        scanf("%d", &array[i].cli.celular);
        printf("Ingrese el precio del producto del cliente %d: ",i);
        scanf("%f", &array[i].precio);
        printf("Ingrese el id del Producto del cliente %d: ",i);
        scanf("%d", &array[i].idProducto);
    }
}

int buscarCliente(compra array[], int n, char nombre[], char sexo, float precioMin)
{   
    for(int i = 0; i < n; i++){
        if(strcmp(array[i].cli.nombre, nombre) == 0 && array[i].cli.sexo == sexo && array[i].precio > precioMin)
            return 1;
    }
    return -1;
}
