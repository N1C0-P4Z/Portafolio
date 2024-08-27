#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int antiguedad;
    char nombrelugartrabajo[100];
    char legajo[30];
}trabajo;

typedef struct{
    char nombre[30];
    char apellido[30];
    int edad;
    trabajo tra;
}persona;

void darDeALta(persona *p, int n);

int main()
{   

    return 0;
}

void darDeALta(persona *p, int n)
{
    for(int i=0; i<n; i++){
        printf("Ingrese el nombre de la persona %d: ", i);
        scanf("%s", (p+i)->nombre);
        getchar();
        printf("Ingrese el apellido de la persona %d: ",i);
        scanf("%s", (p+i)->apellido);
        getchar();
        printf("Ingrese la edad de la persona %d: ",i);
        scanf("%d", &(p+i)->edad);
        printf("Ingrese la antiguedad de la persona %d: ",i);
        scanf("%d", &(p+i)->tra.antiguedad);
        printf("Ingrese el nombre del lugar de trabajo de la persona %d: ",i);
        scanf("%s", (p+i)->tra.nombrelugartrabajo);
        getchar();
        printf("Ingrese el legajo de la persona %d",i);
        scanf("%s", (p+i)-> tra.legajo);
        getchar();
        printf("\n");
    }
}