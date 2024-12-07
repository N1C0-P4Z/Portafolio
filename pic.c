#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char apellido[20];
    char nombre[20];
    int dni;
    char ciudad[30];
    int edad;
}pasajero;

void ingresar_pasajero(pasajero array[], int n);
void buscar(pasajero array[], int n, int dniclave);
int desempatar(pasajero a, pasajero b);
void ordInsercion(pasajero array[],int n);
int busquedaBin(pasajero array[], int n, char claveNombre);

int main()
{   
    int n;
    printf("Ingrese el numero de pasajeros: ");
    scanf("%d", &n);

    pasajero array[n];
    ingresar_pasajero(array,n);

    ordInsercion(array,n);
    printf("El arreglo ordenado es\n");
    for(int i=0; i<n;i++){
        printf("Apellido:%s\n", array[i].apellido);
        printf("Nombre:%s\n", array[i].nombre);
        printf("DNI:%d\n", array[i].dni); 
        printf("Edad:%d\n", array[i].edad);
        printf("Ciudad:%s\n", array[i].ciudad);
        printf("\n");
    }
    char claveNOmbre[30];
    printf("Ingrese el nombre a buscar: ");
    scanf("%s", claveNOmbre);

    int esta = busquedaBin(array,n,claveNOmbre);
    if(esta == 1){
        printf(" esta");
    }else{
        printf("No esta");
    }

    return 0;
}

void ingresar_pasajero(pasajero array[], int n)
{
    for(int i=0; i<n;i++){
        printf("INgrese apellido %d: ",i);
        scanf("%s", array[i].apellido);
        printf("INgrese nombre %d: ",i);
        scanf("%s", array[i].nombre);
        printf("INgrese dni %d: ",i);
        scanf("%d", &array[i].dni);
        printf("INgrese ciudad %d: ",i);
        scanf("%s", array[i].ciudad);
        printf("INgrese edad %d: ", i);
        scanf("%d", &array[i].edad);
    }
}

int desempatar(pasajero a, pasajero b)
{
    if(strcmp(a.apellido,b.apellido)==0){
        return strcmp(a.nombre,b.nombre);
    }
    return strcmp(a.apellido,b.apellido);
}

void ordInsercion(pasajero array[], int n)
{
    int i,j;
    pasajero aux;

    for(i = 1; i < n; i++){
        j = i;
        aux = array[i];
        while(j > 0 && desempatar(aux, array[j - 1]) < 0){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
}

int busquedaBin(pasajero array[], int n, char claveNombre){
    int central,inicio,final;
    char pivot[30];

    inicio = 0;
    final = n-1;
    while(inicio <= final){
        central = (inicio + final)/2;
        strcpy(pivot, array[central].nombre);
        
        if(strcmp(pivot, claveNombre)==0)
            return central;
        else if(strcmp(pivot,claveNombre)<0)
            final = central - 1;
            else
                inicio= central + 1;
    }
    return -1;
}
