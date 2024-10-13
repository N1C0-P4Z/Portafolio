#include <stdio.h>
#include <stdio.h>

typedef struct {
    char nombre[20];
    char apellido[15];
    int edad;
    float notas[3];
}alumno;
void getAlumno(alumno array[], int n);
void ordPromBurbuja(alumno array[], int n);

int main()
{   
    int n;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    alumno array[n];
    getAlumno(array,n);

    ordPromBurbuja(array,n);

    printf("El arreglo ordenado es: ");
    for(int i = 0; i < n; i++){
        float suma = array[i].notas[0] + array[i].notas[1] + array[i].notas[2];
        printf("Nombre: %s\n", array[i].nombre);
        printf("Apellido: %s\n", array[i].apellido);
        printf("Edad: %d\n", array[i].edad);
        printf("Promedio: %.2f\n", suma/3.0);
        printf("\n");
    }
    return 0;
}
void getAlumno(alumno array[], int n)
{
    for(int i = 0; i < n; i++){
        getchar();
        printf("Ingrese el nombre del alumno %d: ",i);
        scanf("%s", array[i].nombre);
        getchar();
        printf("Ingrese el apellido del alumno %d: ",i);
        scanf("%s", array[i].apellido);
        printf("Ingrese la edad del alumno %d: ",i);
        scanf("%d", &array[i].edad);
        for(int j = 0; j < 3; j++){
            printf("Ingrese la nota %d del alumno %d: ",j,i);
            scanf("%f", &array[i].notas[j]);
        }
        printf("\n");
    }
}

void ordPromBurbuja(alumno array[], int n)
{   
    int i,j,indiceIntercambio;
    alumno aux;
    float suma1 = 0, suma2 = 0, promedio1, promedio2;
    i = n-1;

    while(i > 0)
    {
        indiceIntercambio = 0;
        for(j = 0; j< i; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                suma1 += array[j].notas[k];
                suma2 += array[j + 1].notas[k];
            }
            promedio1 = suma1 / 3.0;
            promedio2 = suma2 / 3.0;
            if(promedio1 < promedio2)
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                indiceIntercambio = j;
            }
            suma1 = 0;
            suma2 = 0;
        }
        i = indiceIntercambio;
    }
}
