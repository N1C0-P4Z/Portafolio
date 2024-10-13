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
int busquedaSecuencial(estudiante array[], int n, char clave[]);

int main()
{   
    int n;
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &n);

    estudiante array[n];

    getAlumno(array,n);
    
    int esta = busquedaSecuencial(array,n,"AL123");

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



int busquedaSecuencial(estudiante array[], int n, char clave[])
{   
    for(int i = 0; i < n; i++){
        if(strcmp(clave, array[i].legajo) == 0 )
            return 1;
    }
    return -1;
}
