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

void darDeAlta(persona *p, int n);
float promEdades(persona *p, int n);
int contarVocales(char *p);
int corroborarVocales(persona *p, int n);

int main()
{   
    int n;
    printf("Ingrese el numero de empleados: ");
    scanf("%d", &n);

    persona p[n];
    darDeAlta(p,n);

    for(int i=0; i<n; i++)
    {
        printf("El nombre del empleado %d es %s\n", i,(p+i)->nombre);
        printf("El apellido del empleado %d es %s\n",i,(p+i)->apellido);
        printf("La edad del empleado %d es %d\n",i, (p+i)->edad);
        printf("La antiguedad del empleado %d es %d\n",i,(p+i)->tra.antiguedad);
        printf("EL nombre del lugar del trabajo del empleado %d es %s\n",i,(p+i)->tra.nombrelugartrabajo);
        printf("EL legajo del empleado %d es %s\n",i,(p+i)->tra.legajo);
        printf("\n");
    }
    float promedio= promEdades(p,n);
    printf("El promedio de edades es %f\n",promedio);
    
    printf("La cantidad de personas que trabajan en un lugar cuyo nombre tenga mas de 2 vocales es %d\n",corroborarVocales(p,n));

    return 0;
}

void darDeAlta(persona *p, int n)
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
        printf("Ingrese el legajo de la persona %d: ",i);
        scanf("%s", (p+i)-> tra.legajo);
        getchar();
        printf("\n");
    }
}

float promEdades(persona *p, int n)
{
    int suma=0;
    for(int i=0; i<n; i++){
        suma += (p+i)->edad;
    }
    return suma/( 1.0*n);
}

int contarVocales(char *p)
{   
    int cont=0;
    for(char *ptr = p; *ptr !='\0'; ptr++)
    {
        if(*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' || *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U' )
            cont++;
    }
    return cont;
}

int corroborarVocales(persona *p, int n)
{
    int contV, cont=0;
    for(int i=0; i<n;i++)
    {
        contV= contarVocales((p+i)->tra.nombrelugartrabajo);
        if(contV >2)
            cont++;
    }
    return cont;
}
