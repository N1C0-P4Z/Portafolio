#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int busquedaSecuencial(char array[], int n, char clave);

int main()
{   
    char frase[200];
    printf("Ingrese una frase: ");
    scanf("%[^\n]", frase);

    int largo = strlen(frase);

    int esta = busquedaSecuencial(frase, largo, 'A');

    if(esta == -1)
        printf("La letra 'A' no se encuentra en la frase\n");
    else
        printf("La letra 'A' si esta en la frase\n");

    return 0;
}

int busquedaSecuencial(char array[], int n, char clave)
{
    for(int i = 0; i < n; i++){
        if(clave == array[i])
            return 1;
    }
    return -1;
}