#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 10; 
    int *i_ptr;
    printf("%p\n", &i);
    printf("%p\n", &i_ptr);

    return 0; 
}