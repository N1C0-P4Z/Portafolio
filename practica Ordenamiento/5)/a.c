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
void ordMatBurbuja(estudiantes array[], int n);
void ordLegajoBurbuja(estudiantes array[], int n);

int main()
{   
    int n;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    estudiantes array[n];

    getAlumno(array,n);

    ordMatBurbuja(array,n);

    printf("El arreglo ordenado por Cantidad de Materias Aprobadas de forma creciente es:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i].nombre);
        printf("%s\n", array[i].apellido);
        printf("%d\n", array[i].edad);
        printf("%d\n", array[i].cantMatAprobadas);
        printf("%s\n", array[i].legajo);
        printf("\n");
    }

    ordLegajoBurbuja(array,n);

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

void ordMatBurbuja(estudiantes array[], int n)
{
    int i,j,indiceIntercambio;
    estudiantes aux;
    
    i = n-1;
    while(i > 0){
        indiceIntercambio = 0;
        for(j = 0; j < i; j++)
            if(array[j + 1].cantMatAprobadas < array[j].cantMatAprobadas){
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                indiceIntercambio = j;
            }
        i = indiceIntercambio;
    }
}

void ordLegajoBurbuja(estudiantes array[], int n)
{
    int i,j,indiceIntercambio;
    estudiantes aux;

    i = n-1;
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
