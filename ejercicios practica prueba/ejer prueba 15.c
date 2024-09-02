 #include <stdio.h>
 #include <stdlib.h>

typedef struct
{
    char nombre[30];
    int mate;
    int fisica;
    int lengua;
}estudiante;

void cargarEst(estudiante *array, int n);

int main()
{
    int n;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    estudiante array[n];

    cargarEst(array,n);

    for(int i=0; i<n; i++){
        printf("Datos del estudiante %d\n",i);
        printf("Nombre:%s\n", (array + i)->nombre);
        printf("Nota Mate:%d\n", (array + i)->mate);
        printf("Nota Fisica:%d\n", (array + i)->fisica);
        printf("Nota Lengua:%d\n", (array + i)->lengua);
        printf("\n");
    }

    return 0;
}

void cargarEst(estudiante *array, int n)
{   
    for(int i=0; i<n; i++){
        printf("Ingrese el nombre del estudiante %d: ",i);
        scanf("%s", (array + i)->nombre);
        getchar();
        printf("Ingrese la nota de mate del estudiante %d: ",i);
        scanf("%d", &(array + i)->mate);
        printf("Ingrese la nota de fisica del estudiante %d: ",i);
        scanf("%d", &(array + i)->fisica);
        printf("Ingrese la nota de lengua del estudiante %d: ",i);
        scanf("%d", &(array + i)->lengua);
        printf("\n");
    }
}
