/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar(int arreglo[], int n, int cuadrado){
    int pasada, j;
    for(pasada = 0; pasada < n - 1; pasada++){
        for(j = 0; j < n - pasada - 1; j++){
            if((arreglo[j]*arreglo[j]) > cuadrado){
                int aux = arreglo[j];
                arreglo [j] = arreglo [j+1];
                arreglo[j+1] = aux;
            }
        }
    }
}

int buscar(int arreglo[], int n, int cuadrado) {
    int inf = 0, sup = n - 1, central;

    while (inf <= sup) {
        central = (inf + sup) / 2;
        int valorcentral = arreglo[central];

        if (cuadrado == valorcentral * valorcentral) {
            return central;
        } else if (cuadrado > valorcentral * valorcentral) {
            inf = central + 1;
        } else {
            sup = central - 1;
        }
    }
    return -1;
}
int main()
{
    int n = 6;
    int cuadrado = 36;

    int arreglo[] = {1, 2, 3, 4, 5, -6};

    ordenar(arreglo, n, cuadrado);

    int bandera = buscar(arreglo, n, cuadrado);

    if(bandera != -1){
        printf("El valor se encontro en la posicion %d", bandera + 1);
    }
    else{
        printf("El valor no se encontro");
    }

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    char fecha[20];
    int tamaño;
    int permisos;
}archivo;

void getArchivo(archivo array[], int n);
void ordInsercion(archivo array[], int n);
int busquedaBin(archivo array[], int n, char claveFecha[20], int clavePermisos);
void ordBurbuja(int array[], int n);
int busquedaBin2(int array[], int n, int clave);

int main()
{   
    int n;
    printf("Ingrese la cantidad de archivos: ");
    scanf("%d", &n);

    archivo array[n];

    getArchivo(array,n);

    ordInsercion(array, n);

    int esta = busquedaBin(array, n, "2024-11-12", 5);
    if(esta == -1)
        printf("El archivo con esas caracteristicas no existe\n");
    else    
        printf("El archivo si fue encontrado\n");
    
    int array2[n];
    for(int i = 0; i < n; i++){
        printf("Ingrese el numero %d: ",i);
        scanf("%d", &array2[i]);
    }
    ordBurbuja(array2,n);

    int numeroBuscado = 17;

    int esta2 = busquedaBin2(array2,n,numeroBuscado);
        if(esta2 == -1)
        printf("El archivo con esas caracteristicas no existe\n");
    else    
        printf("El archivo si fue encontrado\n");
    return 0;
}

void getArchivo(archivo array[], int n)
{
    for(int i = 0; i < n; i++){
        getchar();
        printf("Ingrese el nombre del archivo %d: ",i);
        scanf("%s", array[i].nombre);
        getchar();
        printf("Ingrese la fehca del archivo %d: ",i);
        scanf("%s", array[i].fecha);
        printf("Ingrese el tamaño del archivo %d: ",i);
        scanf("%d", &array[i].tamaño);
        printf("Ingrese el permiso del archivo %d: ",i);
        scanf("%d", &array[i].permisos);
        printf("\n");
    }
}

void ordInsercion(archivo array[], int n)
{
    int i,j;
    archivo aux;
    for(i = 1; i < n; i++){
        j = i;
        aux = array[i];
        while(j > 0 && strcmp(aux.nombre,array[j - 1].nombre)<0){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
}

int busquedaBin(archivo array[], int n, char claveFecha[20], int clavePermisos)
{
    int central, inicio,ultimo;
    
    inicio = 0;
    ultimo = n-1;
    while(inicio <= ultimo){
        central = (inicio + ultimo)/2;
        if(strcmp(array[central].fecha, claveFecha) == 0 && array[central].permisos == clavePermisos)
            return central;
        else if(strcmp(array[central].fecha, claveFecha)<0 || (strcmp(array[central].fecha, claveFecha)==0 && array[central].permisos < clavePermisos))
            ultimo = central - 1;
            else    
                inicio = central + 1;
    }
    return -1;
}

void ordBurbuja(int array[], int n)
{
    int i,j,indiceIntercambio;
    int aux;
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
int busquedaBin2(int array[], int n, int clave)
{
    int central,inicio,final;
    int pivot;

    inicio = 0;
    final = n-1;
    while(inicio <= final){
        central = (inicio + final)/2;
        pivot = array[central];
        if(clave == pivot)
            return central;
        else if(clave < pivot)
            final = central - 1;
            else
                inicio = central + 1;
    }
    return -1;
}

