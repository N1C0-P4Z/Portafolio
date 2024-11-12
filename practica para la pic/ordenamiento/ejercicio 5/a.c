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
void ordBurbujaMat(estudiantes array[], int n);
void ordBurbujaLegajo(estudiantes array[], int n);

int main()
{   
    int n;
    printf("ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    estudiantes array[n];

    get_estudiantes(array,n);

    ordBurbujaMat(array,n);

    printf("La matriz ordenada segun la cantidad de materias aprobadas es:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i].nombre);
        printf("%s\n", array[i].apellido);
        printf("%d\n", array[i].total_mat_aprobadas);
        printf("%d\n", array[i].edad);
        printf("%s\n", array[i].legajo);
        printf("\n");
    }

    ordBurbujaLegajo(array,n);

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
void ordBurbujaMat(estudiantes array[], int n)
{
    int i,j,indiceIntercambio;
    estudiantes aux;

    i = n-1;
    while(i > 0)
    {
        indiceIntercambio = 0;
        for(j = 0; j < i; j++)
            if(array[j + 1].total_mat_aprobadas < array[j].total_mat_aprobadas){
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                indiceIntercambio = j;
            }
            i = indiceIntercambio;
    }
}

void ordBurbujaLegajo(estudiantes array[], int n)
{
    int i,j,indiceIntercambio;
    
    estudiantes aux;

    i = n -1;
    while(i > 0){
        indiceIntercambio = 0;
        for(j = 0; j < i; j++)
            if(strcmp(array[j + 1].legajo, array[j].legajo)>0){
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                indiceIntercambio = j;
            }
            i = indiceIntercambio;
    }
}
