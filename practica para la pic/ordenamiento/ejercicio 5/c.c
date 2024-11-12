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
void ordSeleccionMat(estudiantes array[], int n);
void ordSeleccionLegajo(estudiantes array[], int n);

int main()
{   
    int n;
    printf("ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    estudiantes array[n];

    get_estudiantes(array,n);

    ordSeleccionMat(array,n);

    printf("La matriz ordenada segun la cantidad de materias aprobadas es:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i].nombre);
        printf("%s\n", array[i].apellido);
        printf("%d\n", array[i].total_mat_aprobadas);
        printf("%d\n", array[i].edad);
        printf("%s\n", array[i].legajo);
        printf("\n");
    }

    ordSeleccionLegajo(array,n);

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

void ordSeleccionMat(estudiantes array[], int n)
{
    int i,j,indiceMenor;
    estudiantes aux;

    for(i = 0; i < n - 1; i++){
        indiceMenor = i;
        for(j = i + 1;j < n; j++)
            if(array[j].total_mat_aprobadas < array[indiceMenor].total_mat_aprobadas)
                indiceMenor = j;
        if (i != indiceMenor){
            aux = array[i];
            array[i] = array[indiceMenor];
            array[indiceMenor] = aux;
        }
    }
}

void ordSeleccionLegajo(estudiantes array[], int n)
{
    int i,j,indiceMenor;    
    estudiantes aux;

    for(i = 0; i < n - 1; i++){
        indiceMenor = i;
        for(j = i + 1; j < n; j++)
            if(strcmp(array[j].legajo,array[indiceMenor].legajo) > 0)
                indiceMenor = j;
        
        if(i != indiceMenor){
            aux = array[i];
            array[i] = array[indiceMenor];
            array[indiceMenor] = aux;
        }
    }
}
