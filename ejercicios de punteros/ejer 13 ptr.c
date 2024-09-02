#include <stdio.h>
#include <stdlib.h>

void intercambiar(float *, float *);

int main()
{   
    float x,y;

    printf("Ingrese un flotante: ");
    scanf("%f", &x); 

    printf("Ingrese otro flotante: ");
    scanf("%f", &y); 

    printf("Los valores antes de cambiar son de %.2f y %.2f\n", x,y);

    intercambiar(&x, &y);

    printf("El nuevo valor de x es %.2f\n", x);
    printf("El nuevo valor de y es %.2f\n", y);

    return 0; 
}
void intercambiar(float *x, float *y)
{
    float aux = *x;
    *x = *y;
    *y = aux;
}