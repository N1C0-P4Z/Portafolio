#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=10;
    int *b= &a;
    int **c= &b;

    printf("%p\n", &a);
    printf("%p\n", b);
    printf("%p\n", *c);

    return 0; 
}