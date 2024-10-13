#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nombre[20];
    char apellido[15];
    int edad;
    float nota[3];
}alumno;

float prom(float nota[]);
void getAlumno4(alumno array[], int n);
void ordQuicksort(alumno array[], int primero, int ultimo);

int main()
{   
    int n;

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    alumno array[n];

    getAlumno4(array,n);
    
    ordQuicksort(array,0,n-1);

    printf("El arreglo ordenado es: ");
    for(int i = 0; i < n; i++){
        float suma = array[i].nota[0] + array[i].nota[1] + array[i].nota[2];
        printf("Nombre: %s\n", array[i].nombre);
        printf("Apellido: %s\n", array[i].apellido);
        printf("Edad: %d\n", array[i].edad);
        printf("Promedio: %.2f\n", suma/3.0);
        printf("\n");
    }
    return 0;
}

void getAlumno4(alumno array[], int n)
{
    for(int i = 0; i<n; i++){
        getchar();
        printf("Ingrese el nombre del alumno %d: ",i);
        scanf("%s", array[i].nombre);
        getchar();
        printf("Ingrese el apellido del alumno %d: ",i);
        scanf("%s", array[i].apellido);
        printf("Ingrese la edad del alumno %d: ",i);
        scanf("%d", &array[i].edad);
        for(int j = 0; j<3; j++){
            printf("Ingrese la nota %d del alumno %d: ",j,i);
            scanf("%f", &array[i].nota[j]);
        }
        printf("\n");
    }
}

void ordQuicksort(alumno array[], int primero, int ultimo)
{
    int i,j,central;
    alumno pivot, aux;

    central = (primero + ultimo)/2;
    pivot = array[central];

    float promPivot = prom(pivot.nota);

    i = primero;
    j= ultimo;

    do{
        while(prom(array[i].nota)> promPivot) i++;
        while(prom(array[j].nota)< promPivot) j--;

        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);

    if(primero < j)
        ordQuicksort(array,primero,j);
    if(i < ultimo)
        ordQuicksort(array,i,ultimo);
}

float prom(float nota[]){
    float suma = 0;

    for(int k = 0; k < 3; k++)
        suma += nota[k];
    
    return suma / 3.0;
}
