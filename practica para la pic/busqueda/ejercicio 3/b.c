#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char legajo[30];
    char nombre[20];
    float nota_cuatrimestre;
}estudiante;

void get_alumno(estudiante array[], int n);
void ordInsercion(estudiante array[], int n);
int busquedaSecuencial(estudiante array[], int n, char clave[]);

int main()
{   
    int n;

    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &n);

    estudiante array[n];

    get_alumno(array,n);
    
    ordInsercion(array,n);

    int esta = busquedaSecuencial(array,n,"AL123");

    if(esta == -1)
        printf("El estudiante con legajo AL123 no se encuentra en la matriz\n");
    else
        printf("El estudiante con legajo AL123 si se encuantra en la matriz\n");
        
    return 0;
}

void get_alumno(estudiante array[], int n)
{
    for(int i = 0; i < n; i++){
        getchar();
        printf("Ingrese el legajo del alumno %d: ",i);
        scanf("%s", array[i].legajo);
        getchar();
        printf("Ingrese el nombre del alumno %d: ",i);
        scanf("%s", array[i].nombre);
        printf("Ingrese la nota del cuatrimestre del alumno %d: ",i);
        scanf("%f", &array[i].nota_cuatrimestre);
        printf("\n");
    }
}
void ordInsercion(estudiante array[], int n)
{
    int i,j;
    estudiante aux;

    for(i = 1; i < n; i++){
        j = i;
        aux = array[i];
        while(j > 0 && strcmp(aux.legajo, array[j - 1].legajo)<0){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
}
int busquedaSecuencial(estudiante array[], int n, char clave[])
{
    for(int i = 0; i < n; i++){
        if(strcmp(clave, array[i].legajo) == 0)
            return 1;
    }
    return -1;
}