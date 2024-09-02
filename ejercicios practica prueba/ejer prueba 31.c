#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nombre[15];
    int edad;
}persona;

void cargarStruct(int n, persona *p);
persona *ordenarPorNombree(int *n, persona *p);

int main()
{   
    int n;

    printf("Ingrese el numero de personas: ");
    scanf("%d", &n);

    persona array[n];
    persona *p = array;

    cargarStruct(n,p);

    ordenarPorNombree(&n,p);
    printf("Las personas ordenadas por nombre son:\n");

    for(int i=0; i<n; i++){
        printf("Persona %d\n",i);
        printf("Nombre: %s\n", (array + i)->nombre);
        printf("Edad: %d\n", (array + i)->edad);
        printf("\n");
    }

    return 0;
}

void cargarStruct(int n, persona *p)
{
    for(int i=0; i<n; i++){
        printf("Ingrese el nombre de la persona %d: ",i);
        scanf("%s", (p + i)->nombre);
        getchar();
        printf("Ingrese la edad de la persona %d: ",i);
        scanf("%d", &(p + i)->edad);
    }
    printf("\n");
}

persona *ordenarPorNombree(int *n, persona *p)
{   
    persona aux;
    for(int i=0; i<*n-1; i++){
        for(int j = i + 1; j < *n; j++){
            if(strcmp(( p + i)->nombre, (p + j)->nombre)>0 ){
                aux = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = aux;
            }
        }
    }
    return p;
}
