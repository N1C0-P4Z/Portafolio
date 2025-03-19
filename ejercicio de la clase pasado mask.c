#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int masc = 1<<31, w = 0;    
    int num = 237;
    while (masc){
        w = w + (num & masc ) /masc;
        masc >>= 1;
    }
    masc = 1<<31;
    printf("%i ", (num & masc)/masc);

    masc >>= 1;
        masc = masc >> 1;
    return 0;
}
