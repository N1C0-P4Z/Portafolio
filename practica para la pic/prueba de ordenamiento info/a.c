#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    char sexo;
    char rol[30];
}personajes;

void get_personajes(personajes array[], int n);
int compararPersonajes(personajes a, personajes b);
void ordInsercion(personajes array[], int n);
int busquedaBinaria(personajes array[], int n, char claveRol[30]);

int main()
{   int n;
    printf("Ingrese la cantidad de personajes: ");
    scanf("%d", &n);

    personajes array[n];

    get_personajes(array,n);

    ordInsercion(array,n);

    printf("La matriz ordenada segun el rol de los personajes es:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i].nombre);
        printf(" %c\n", array[i].sexo);
        printf("%s\n", array[i].rol);
        printf("\n");
    }

        int esta = busquedaBinaria(array,n,"Support");

    if(esta == -1)
        printf("El rol Support no se encontra en la matriz");
    else    
        printf("El rol Support si se encontro en la matriz");

    return 0;
}

void get_personajes(personajes array[], int n)
{
    for(int i = 0; i < n; i++){
        getchar();
        printf("Ingrese el nombre del personaje %d: ",i);
        scanf("%s", array[i].nombre);
        getchar();
        printf("Ingrese el sexo(F o M) del personaje %d: ",i);
        scanf("%c", &array[i].sexo);
        getchar();
        printf("Ingrese el rol del personaje %d: ",i);
        scanf("%s", array[i].rol);
    }
}

int compararPersonajes(personajes a, personajes b)
{   
    if(strcmp(a.rol,b.rol)==0){
        return strcmp(a.nombre, b.nombre);
    }
    return strcmp(a.rol, b.rol);
}
void ordInsercion(personajes array[], int n)
{
    int i,j;
    personajes aux;

    for(i = 1; i < n; i++){
        j = i;
        aux = array[i];
        while(j > 0 && compararPersonajes(aux, array[j - 1]) <0){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
}

int busquedaBinaria(personajes array[], int n, char claveRol[30])
{   
    int central, inicio, ultimo;
    char pivot[30];

    inicio = 0;
    ultimo = n-1;

    while(inicio <= ultimo){
        central = (inicio + ultimo)/2;
        strcpy(pivot, array[central].rol);

        if(strcmp(claveRol, pivot) == 0)
            return central;
        else if(strcmp(claveRol, pivot)<0)
            ultimo = central - 1;
            else    
                inicio = central + 1;
    }
    return -1;
}
