#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nombre[20];
    char apellido[15];
    int edad;
    float nota[3];
}alumno;

void getAlumno2(alumno array[], int n);
void ordSeleccion(alumno array[], int n);

int main()
{   
    int n;

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    alumno array[n];

    getAlumno2(array,n);
    
    ordSeleccion(array,n);

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

void getAlumno2(alumno array[], int n)
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

void ordSeleccion(alumno array[], int n)
{   
    int i,j,indiceMenor;
    alumno aux;
    float suma1, suma2, promedio1, promedio2;

    for(i = 0; i < n-1; i++){
        indiceMenor = i;
        for(j = i + 1; j < n; j++){
            suma1 = 0;
            suma2 = 0;
            for(int k = 0; k < 3; k++){
                suma1 += array[j].nota[k];
                suma2 += array[indiceMenor].nota[k];
            }
            promedio1 = suma1 / 3.0;
            promedio2 = suma2 / 3.0;

            if(promedio1 < promedio2)
                indiceMenor = j;
            
            if(i != indiceMenor){
                aux = array[i];
                array[i] = array[indiceMenor];
                array[indiceMenor] = aux;
            }
        }
    }
}
