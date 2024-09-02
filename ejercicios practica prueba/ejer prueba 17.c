#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int antiguedad;
    char nombreTrabajo[100];
    char legajo[30];

}trabajo;

typedef struct 
{
    char nombre[30];
    char apellido[20];
    int edad;
    trabajo tra;
}persona;

void darDeAlta1(persona *p, int n);
float promEdades1(persona *p, int n);
int esVocal(char *p);
int corroborarVocales1(persona *p, int n);

int main()
{
    int n;
    printf("Ingrese la cantidad de empleados: ");
    scanf("%d",&n);

    persona array[n];
    darDeAlta1(array,n);

    for(int i=0; i<n; i++){
        printf("Persona %d\n",i);
        printf("Nombre:%s\n", (array + i)->nombre);
        printf("Apellido:%s\n", (array + i)->apellido);
        printf("Edad:%d\n", (array + i)-> edad);
        printf("Antiguedad:%d\n", (array + i)->tra.antiguedad);
        printf("Nombre del lugar de trabajo:%s\n", (array + i)->tra.nombreTrabajo);
        printf("Legajo:%s\n", (array + i)->tra.legajo);
        printf("\n");
    }

    float prom= promEdades1(array, n);
    printf("El promedio de las edades es %.2f\n", prom);

    int contador = corroborarVocales1(array,n);

    printf("La cantidad de empleados que trabajan en  un lugar donde el nombre tiene mas de 2 vocales es %d\n", contador);
    return 0;
}

void darDeAlta1(persona *p, int n)
{
    for(int i=0; i<n; i++){
        printf("Ingrese el nombre de la persona %d: ",i);
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
        scanf("%s", (p+i)->tra.nombreTrabajo);
        getchar();
        printf("Ingrese el legajo de la persona %d: ",i);
        scanf("%s", (p+i)->tra.legajo);
        getchar();
        printf("\n");
    }
}

float promEdades1(persona *p, int n)
{   
    int suma=0;
    for(int i=0; i<n; i++){
        suma += (p + i)->edad;
    }
    return suma/(1.0 * n);
}

int esVocal(char *p)
{
    int cont=0;
    for(p; *p !='\0'; p++){
        if(*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' || *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U'){
            cont++;
        }
    }
    return cont;
}
int corroborarVocales1(persona * p, int n)
{   
    int cont1=0;
    int contV;
    for(int i=0; i<n; i++){
        contV = esVocal((p + i)->tra.nombreTrabajo);
        if(contV>2)
            cont1++;
    }
    return cont1;
}