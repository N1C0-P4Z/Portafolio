#include <stdio.h>
#include <stdlib.h>

int strleenn(char *frase);

int main()
{   
    char frase[100];

    printf("Ingrese una frase: ");
    scanf("%[^\n]", frase);
    getchar();

    printf("El largo de la frase es %d", strleenn(frase));

    return 0;
}

int strleenn(char *frase)
{   
    int cont;
    for(cont =0; *frase !='\0'; frase++)
        cont++;
    return cont;
}
