#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    char apellido[20];
    int cantMatAprobadas;
    int edad;
    char legajo[15];
}estudiantes;

void getAlumno(estudiantes array[], int n);
void ordMatQuicksort(estudiantes array[], int primero, int ultimo);
void ordLegajoQuicksort(estudiantes array[], int primero, int ultimo);

int main()
{   
    int n;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    estudiantes array[n];

    getAlumno(array,n);

    ordMatQuicksort(array,0,n-1);

    printf("El arreglo ordenado por Cantidad de Materias Aprobadas de forma creciente es:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i].nombre);
        printf("%s\n", array[i].apellido);
        printf("%d\n", array[i].edad);
        printf("%d\n", array[i].cantMatAprobadas);
        printf("%s\n", array[i].legajo);
        printf("\n");
    }

    ordLegajoQuicksort(array,0,n-1);

    printf("El arreglo ordenado por legajo de forma decreciente es:\n");
    for(int j = 0; j < n; j++){
        printf("%s\n", array[j].nombre);
        printf("%s\n", array[j].apellido);
        printf("%d\n", array[j].edad);
        printf("%d\n", array[j].cantMatAprobadas);
        printf("%s\n", array[j].legajo);
        printf("\n");
    }

    return 0;
}

void getAlumno(estudiantes array[], int n)
{
    for(int i = 0; i < n; i++)
    {   
        getchar();
        printf("Ingrese el nombre del estudiante %d: ",i);
        scanf("%s", array[i].nombre);
        getchar();
        printf("Ingrese el apellido del estudiante %d: ",i);
        scanf("%s", array[i].apellido);
        printf("Ingrese la edad del alumno %d: ",i);
        scanf("%d", &array[i].edad);
        printf("Ingrese la cantidad de materias aprobadas del estudiante %d: ",i);
        scanf("%d", &array[i].cantMatAprobadas);
        getchar();
        printf("Ingrese el legajo del alumno %d: ",i);
        scanf("%s", array[i].legajo);
        printf("\n");
    }
}

void ordMatQuicksort(estudiantes array[], int primero, int ultimo)
{
    int i,j,central;
    estudiantes pivot,aux;

    central = (primero + ultimo)/2;
    pivot = array[central];

    i=primero;
    j=ultimo;

    do{
        while(array[i].cantMatAprobadas < pivot.cantMatAprobadas) i++;
        while(array[j].cantMatAprobadas > pivot.cantMatAprobadas) j--;

        if(i <=j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);

    if(primero < j)
        ordMatQuicksort(array,primero,j);
    if(i < ultimo)
        ordMatQuicksort(array,i,ultimo);
}

void ordLegajoQuicksort(estudiantes array[], int primero, int ultimo)
{
    int i,j,central;
    estudiantes pivot,aux;

    central = (primero + ultimo)/2;
    pivot = array[central];

    i=primero;
    j=ultimo;

    do{
        while(strcmp(array[i].legajo, pivot.legajo)<0) i++;
        while(strcmp(array[j].legajo, pivot.legajo)>0) j--;

        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);

    if(primero < j)
        ordLegajoQuicksort(array,primero,j);
    if(i < ultimo)
        ordLegajoQuicksort(array,i,ultimo);
}
