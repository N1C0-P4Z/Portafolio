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
void ordBurbuja(estudiante array[], int n);
int busquedaBin(estudiante array[], int n, char clave[]);

int main()
{   
    int n;

    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &n);

    estudiante array[n];

    get_alumno(array,n);
    
    ordBurbuja(array,n);

    int esta = busquedaBin(array,n,"AL123");

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

void ordBurbuja(estudiante array[], int n)
{
    int i,j,indiceIntercambio;
    estudiante aux;

    i = n-1;

    while(i > 0){
        indiceIntercambio = 0;
        for(j = 0; j < i; j++)
            if(strcmp(array[j + 1].legajo, array[j].legajo)<0){
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                indiceIntercambio = j;
            }
            i = indiceIntercambio;
    }
}

int busquedaBin(estudiante array[], int n, char clave[])
{
    int central, inicio, ultimo;
    estudiante pivot;

    inicio = 0;
    ultimo = n-1;

    while(inicio <= ultimo){
        central = (inicio + ultimo)/2;
        pivot = array[central];

        if(strcmp(clave, pivot.legajo) ==0)
            return central;
        else if(strcmp(clave, pivot.legajo)<0)
                ultimo = central - 1;
            else
                inicio = central + 1;
    }
    return -1;
}
