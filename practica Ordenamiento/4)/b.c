#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nombre[20];
    char apellido[15];
    int edad;
    float nota[3];
}alumno;

void getAlumno1(alumno array[], int n);
void ordInsercion(alumno array[], int n);

int main()
{   
    int n;

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    alumno array[n];

    getAlumno1(array,n);
    
    ordInsercion(array,n);

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

void getAlumno1(alumno array[], int n)
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

void ordInsercion(alumno array[], int n)
{   
    int i,j;
    alumno aux;
    float suma = 0, promedio;

    for(i = 1; i < n; i++){
        j = i;
        aux = array[i];
        suma = 0;
        for(int k = 0; k < 3; k++)
            suma += aux.nota[k];
        promedio = suma/3.0;
        while(j > 0 && promedio > ((array[j - 1].nota[0] + array[j - 1].nota[1] + array[j - 1].nota[2])/ 3.0)){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
}
