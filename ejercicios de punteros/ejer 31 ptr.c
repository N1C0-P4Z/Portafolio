#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nombre[15];
    int edad;
}persona;

void cargarPersonas(persona *p, int n);
persona* ordenarPorNombre(persona *p, int *n);
persona* ordenarPorEdad(persona *p, int *n);

int main()
{   
    int n;
    printf("Ingrese el numero de personas: ");
    scanf("%d", &n);

    persona array[n];
    cargarPersonas(array,n);

    ordenarPorNombre(array, &n);
    printf("Las personas ordenadas alfabeticamente son\n");

    for(int i = 0 ; i<n ; i++){
        printf("Persona %d\n",i);
        printf("Nombre:%s\n", (array + i)-> nombre);
        printf("Edad:%d\n", (array + i)->edad);
        printf("\n");
    }

    ordenarPorEdad(array,&n);
    printf("Las personas ordenadas de edad mayor a menor son\n");

    for(int i= 0; i<n; i++){
        printf("Persona %d\n",i);
        printf("Nombre:%s\n", (array + i)->nombre);
        printf("Edad:%d\n", (array + i)->edad);
        printf("\n");
    }
    return 0;
}

void cargarPersonas(persona *p, int n)
{   
    for(int i = 0; i<n ; i++){
        printf("Ingrese el nombre de la persona %d: ",i);
        scanf("%s", (p+i)->nombre);
        getchar();
        printf("Ingrese la edad de la persona %d: ",i);
        scanf("%d", &((p+i)->edad));
    }
}

persona *ordenarPorNombre(persona *p, int *n)
{
    persona aux;
    for(int i = 0; i < *n-1; i++){
        for(int j = i + i; j< *n; j++){
            if(strcmp((p + i)-> nombre, (p + j)-> nombre)>0){
                aux = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = aux;
            }
        }
    }
    return p;
}

persona *ordenarPorEdad(persona *p, int *n)
{   
    persona aux;
    for(int i=0; i< *n-1; i++){
        for(int j = i + 1; j < *n; j++){
            if(( p + i)-> edad < ( p + j)->edad){
                aux = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = aux;
            }
        }
    }
    return p;
}
