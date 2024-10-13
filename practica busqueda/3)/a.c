#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char legajo[30];
    char nombre[20];
    float notaCuatrimestral;
}estudiante;

void getAlumno(estudiante array[], int n);
void ordSeleccion(estudiante array[], int n);
int busquedaBinaria(estudiante array[], int n, char clave[]);

int main()
{   
    int n;
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &n);

    estudiante array[n];

    getAlumno(array,n);
    
    ordSeleccion(array,n);
    
    int esta = busquedaBinaria(array,n,"AL123");

    if(esta == -1)
        printf("El estudiante con el legajo 'AL123' no se encuentra en la lista");
    else
        printf("El estudiante con el legajo 'AL123' esta en la lista");

    return 0;
}

void getAlumno(estudiante array[], int n)
{
    for(int i = 0; i < n; i++){
        getchar();
        printf("Ingrese el legajo del estudiante %d: ",i);
        scanf("%s", array[i].legajo);
        getchar();
        printf("Ingrese el nombre del estudiante %d: ",i);
        scanf("%s", array[i].nombre);
        printf("Ingrese la edad del estudiante %d: ",i);
        scanf("%f", &array[i].notaCuatrimestral);
        printf("\n");
    }
}

void ordSeleccion(estudiante array[], int n)
{
    int i,j,indiceMenor;

    estudiante aux;
    
    for(i = 0; i < n-1; i++){
        indiceMenor = i;
        for(j = i + 1; j < n; j++)
            if(strcmp(array[j].legajo, array[indiceMenor].legajo)<0)
                indiceMenor = j;
        if(i != indiceMenor){
            aux = array[i];
            array[i] = array[indiceMenor];
            array[indiceMenor] = aux;
        }
    }
}

int busquedaBinaria(estudiante array[], int n, char clave[])
{   
    int central, inicio, ultimo;
    estudiante pivot;

    inicio = 0;
    ultimo = n-1;

    while(inicio <= ultimo){
        central = (inicio + ultimo)/2;
        pivot = array[central];

        if(strcmp(clave, pivot.legajo) == 0)
            return central;
        else if(strcmp(clave, pivot.legajo) < 0)
                ultimo = central - 1;
        else 
            inicio = central + 1;
    }
    return -1;
}
