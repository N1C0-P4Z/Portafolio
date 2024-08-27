#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void darCadReves(char *frase, char *reves, int len);

int main()
{
    int len;
    printf("len? ");
    scanf("%i", &len);

    char frase[len];
    char reves[len];

    printf("Ingrese una frase: ");
    scanf("%s", frase);

    darCadReves(frase, reves, len);
    printf("");


    for(int i=0; i<len; i++){
    printf("Del reves la frase: %s", reves[i]);
    }

    return 0;
}
void darCadReves(char *frase, char *reves, int len){
    for(int i = 0, j = len; i<len ; i++, j--){
        *(reves + i) = *(frase + j);
    }
}
