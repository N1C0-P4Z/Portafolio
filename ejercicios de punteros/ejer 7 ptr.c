#include <stdio.h>
#include <stdlib.h>

int main()
{   
    struct data
    {
        int *ptr;
        int num;
    }a;

    a.ptr = &(a.num);
    /* Segun el apunte de punteros seria con **/
    return 0; 
}