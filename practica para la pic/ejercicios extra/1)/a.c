#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float precio;
    int idProducto;
}producto;

typedef struct{
    int DNI;
    char nombre[30];
    char apellido[30];
    char sexo;
    int edad;
    int numero_celular;
}cliente;

typedef struct{
    producto produ;
    cliente cli;
}compra;

typedef struct{
    cliente mayoresDeEdad[200];
    int cantidad;
}arrayMayores;

void get_compra(compra array[], int n);
void ordBurbuja(compra array[], int n);
int buscarCLiente(compra array[], int n, char claveNombre[30], char claveSexo,float clavePrecio);
arrayMayores obtenerMayoresDeEdad(compra array[], int n);

int main()
{   int n;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &n);

    compra array[n];

    get_compra(array,n);

    ordBurbuja(array,n);

    int esta = buscarCLiente(array,n,"Nico", 'M', 1000);

    if(esta == -1)
        printf("NO existe un cliente con tales caracteristicas\n");
    else{
        printf("Cliente encontrado:\n");
        printf("Nombre:%s\n", array[esta].cli.nombre);
        printf("Apellido:%s\n", array[esta].cli.apellido);
        printf("DNI:%d\n", array[esta].cli.DNI);
        printf("Sexo:%c\n", array[esta].cli.sexo);
        printf("Edad:%d\n", array[esta].cli.edad);
        printf("Numero de Celular:%d\n", array[esta].cli.numero_celular);
    }
    // 1 hecho
    //2
    arrayMayores mayores[] = obtenerMayoresDeEdad(array,n);

    printf("Los clientes mayores de edad son:\n");
    for(int i = 0; i < n; i++){
        printf("Nombre:%s\n", mayores[i].);
        printf("Apellido:%s\n", mayores[i].apellido);
        printf("DNI:%d\n", mayores[i].DNI);
        printf("Sexo:%c\n", mayores[i].sexo);
        printf("Edad:%d\n", mayores[i].edad);
        printf("Numero de Celular:%d\n", mayores[i].numero_celular);
    }

    return 0;
}

void get_compra(compra array[], int n)
{
    for(int i = 0; i < n; i++){
        printf("INgrese el DNI del cliente de la compra %d: ",i);
        scanf("%d", &array[i].cli.DNI);
        getchar();
        printf("INgrese el nombre del cliente de la compra %d: ",i);
        scanf("%s", array[i].cli.nombre);
        getchar();
        printf("INgrese el apellido del cliente de la compra %d: ",i);
        scanf("%s", array[i].cli.apellido);
        getchar();
        printf("INgrese el sexo(F o M) del cliente de la compra %d: ",i);
        scanf("%c", &array[i].cli.sexo);
        printf("INgrese la edad del cliente de la compra %d: ",i);
        scanf("%d", &array[i].cli.edad);
        printf("INgrese el numero de telefono del cliente de la compra %d: ",i);
        scanf("%d", &array[i].cli.numero_celular);
        printf("INgrese el precio del producto que el cliente compra %d: ",i);
        scanf("%f", &array[i].produ.precio);
        printf("INgrese el ID del producto que el cliente compra %d: ",i);
        scanf("%d", &array[i].produ.idProducto);
        printf("\n");
    }
}

void ordBurbuja(compra array[], int n)
{
    int i,j,indiceIntercambio;
    compra aux;

    i = n - 1;
    while( i > 0){
        indiceIntercambio = 0;
        for(j = 0; j < i; j++)
            if(strcmp(array[j + 1].cli.nombre, array[j].cli.apellido)<0){
                aux= array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                indiceIntercambio = j;
            }
            i = indiceIntercambio;
    }
}

int buscarCLiente(compra array[], int n, char claveNombre[30], char claveSexo, float clavePrecio)
{   
    int central, inicio = 0, ultimo = n -1;

    while(inicio <= ultimo){
        central = (inicio + ultimo)/2;
        if(strcmp(claveNombre, array[central].cli.nombre) == 0 && claveSexo == array[central].cli.sexo && clavePrecio < array[central].produ.precio)
            return central;
        else if (strcmp(claveNombre, array[central].cli.nombre) < 0)
            ultimo = central - 1;
            else 
                inicio = central + 1;
    }
    return -1;
}

arrayMayores obtenerMayoresDeEdad(compra array[], int n)
{   
    arrayMayores resultado;
    resultado.cantidad = 0;
    for(int i = 0; i < n; i++){
        if(array[i].cli.edad >= 18)
            resultado.mayoresDeEdad[resultado.cantidad++] = array[i];
    }
    return resultado;
}
