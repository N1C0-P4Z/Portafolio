#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float matematica;
    float fisica;
    float lengua;
}nota;

void darNotas(nota *p);

int main()
{   
    nota p;
    darNotas(&p);
    
    printf("La nota de mate del alumno es:%.2f\n", p.matematica);
    printf("La nota de fisica del alumno es:%.2f\n", p.fisica);
    printf("La nota de lengua del alumno es:%.2f\n", p.lengua);

    return 0; 
}
void darNotas(nota *p)
{
        printf("Ingrese la nota de Matematica del alumno: ");
        scanf("%f", &p->matematica);
        printf("Ingrese la nota de fisica del alumno: ");
        scanf("%f", &p->fisica);
        printf("Ingrese la nota de Lengua del estudiante: ");
        scanf("%f", &p->lengua);
        printf("\n");
}