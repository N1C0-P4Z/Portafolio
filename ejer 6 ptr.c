#include <stdio.h>
#include <stdlib.h>

int main()
{   
    /*El puntero a contiene la direcci´on de memoria del puntero b que contiene la direcci´on de memoria del
entero c. ¿Cu´al de las siguientes expresiones le asigna el valor 30 al entero c?
*/
    int c=0;
    int *b = &c;
    int **a = &b;

    printf("EL valor de c es %d\n\n", c);

    **a = 30;

    printf("El valor de c es %d\n",c);
    
    return 0; 
}