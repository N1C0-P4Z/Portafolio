#include <stdio.h>
#include <stdlib.h>

char *strcatt1(char *ptr1, char *ptr2);

int main()
{   
    char frase1[200], frase2[200];

    printf("Ingrese la primer frase: ");
    scanf("%[^\n]", frase1);
    getchar();

    printf("Ingrese la segunda frase: ");
    scanf("%[^\n]", frase2);

    printf("\n%s\n", strcatt1(frase1,frase2));

    return 0;
}

char *strcatt1(char *ptr1, char *ptr2)
{   
    char *aux1;
    char *aux2;

    for(aux2 = *ptr1; *aux2 != '\0'; aux2++);
    for(aux1 = *ptr2; *aux1 != '\0'; aux1++, aux2++)
        *aux2 = *aux1;
    *aux2 = '\0';

    return aux2;
}
