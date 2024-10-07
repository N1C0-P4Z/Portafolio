#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main()
{   
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("El factorial de %d es %d\n", n, factorial(n));
    return 0;
}
int factorial(int n)
{
    if(n == 0 )
        return 1;
    else
        return n * factorial(n -1);
}