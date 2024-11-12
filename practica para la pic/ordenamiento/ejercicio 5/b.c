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
void ordInsercionMat(estudiantes array[], int n);
void ordInsercionLegajo(estudiantes array[], int n);

int main()
{   
    int n;
    printf("ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    estudiantes array[n];

    get_estudiantes(array,n);


    ordInsercionMat(array,n);

    printf("La matriz ordenada segun la cantidad de materias aprobadas es:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i].nombre);
        printf("%s\n", array[i].apellido);
        printf("%d\n", array[i].total_mat_aprobadas);
        printf("%d\n", array[i].edad);
        printf("%s\n", array[i].legajo);
        printf("\n");
    }

    ordInsercionLegajo(array,n);

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

void ordInsercionMat(estudiantes array[], int n)
{
    int i,j;
    estudiantes aux;

    for(i = 1; i < n; i++){
        j = i;
        aux = array[i];
        while(j > 0 && aux.total_mat_aprobadas < array[j - 1].total_mat_aprobadas){
            array[j] = array[j -1];
            j--;
        }
        array[j] = aux;

    }
}

void ordInsercionLegajo(estudiantes array[], int n)
{
    int i,j;
    estudiantes aux;

    for(i = 1; i < n; i++){
        j = i;
        aux = array[i];
        while(j > 0 && strcmp(aux.legajo, array[j - 1].legajo)>0){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
}
