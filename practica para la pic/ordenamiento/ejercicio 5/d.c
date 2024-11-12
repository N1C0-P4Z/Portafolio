#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    char apellido[20];
    int total_mat_aprobadas;
    int edad;
    char legajo[15];
}estudiantes;

void get_estudiantes(estudiantes array[], int n);
void ordQuicksortMat(estudiantes array[], int primero, int ultimo);
void ordQuicksortLegajo(estudiantes array[], int primero, int ultimo);

int main()
{   
    int n;
    printf("ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    estudiantes array[n];

    get_estudiantes(array,n);

    ordQuicksortMat(array,0,n-1);

    printf("La matriz ordenada segun la cantidad de materias aprobadas es:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i].nombre);
        printf("%s\n", array[i].apellido);
        printf("%d\n", array[i].total_mat_aprobadas);
        printf("%d\n", array[i].edad);
        printf("%s\n", array[i].legajo);
        printf("\n");
    }

    ordQuicksortLegajo(array,0,n-1);

    printf("La matriz ordenada segun el legajo es:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i].nombre);
        printf("%s\n", array[i].apellido);
        printf("%d\n", array[i].total_mat_aprobadas);
        printf("%d\n", array[i].edad);
        printf("%s\n", array[i].legajo);
        printf("\n");
    }
    return 0;
}

void get_estudiantes(estudiantes array[], int n)
{
    for(int i = 0; i < n; i++){
        getchar();
        printf("Ingrese el nombre del alumno %d: ",i);
        scanf("%s", array[i].nombre);
        getchar();
        printf("Ingrese el apellido del alumno %d: ",i);
        scanf("%s", array[i].apellido);
        printf("Ingrese la cantidad de materias aprobadas del alumno %d: ",i);
        scanf("%d", &array[i].total_mat_aprobadas);
        printf("Ingrese la edad del alumno %d: ",i);
        scanf("%d", &array[i].edad);
        getchar();
        printf("Ingrese el legajo del alumno %d: ",i);
        scanf("%s", array[i].legajo);
        printf("\n");

        
    }
}

void ordQuicksortMat(estudiantes array[], int primero, int ultimo)
{
    int i,j,central;
    estudiantes aux,pivot;

    central = (primero + ultimo)/2;
    pivot = array[central];

    i = primero;
    j = ultimo;

    do{
        while(array[i].total_mat_aprobadas < pivot.total_mat_aprobadas)i++;
        while(array[j].total_mat_aprobadas > pivot.total_mat_aprobadas)j--;

        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);

    if(primero < j)
        ordQuicksortMat(array,primero,j);
    if(i < ultimo)
        ordQuicksortMat(array,i,ultimo);
}

void ordQuicksortLegajo(estudiantes array[], int primero, int ultimo)
{
    int i,j,central;
    estudiantes aux,pivot;

    central = (primero + ultimo)/2;
    pivot = array[central];

    i = primero;
    j = ultimo;

    do{
        while(strcmp(array[i].legajo, pivot.legajo)<0)i++;
        while(strcmp(array[i].legajo, pivot.legajo)>0)j--;

        if(i <= j){
            aux= array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);

    if(primero < j)
        ordQuicksortLegajo(array,primero,j);

    if(i < ultimo)
        ordQuicksortLegajo(array,i,ultimo);
}
