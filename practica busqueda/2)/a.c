#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordInsercion(char array[], int n);
int busquedaBinaria(char array[], int n, char clave);

int main()
{   
    char frase[200];
    printf("Ingrese una frase: ");
    scanf("%[^\n]", frase);

    int largo = strlen(frase);

    ordInsercion(frase, largo);

    int esta = busquedaBinaria(frase, largo, 'A');

    if(esta == -1)
        printf("La letra 'A' no se encuentra en la frase\n");
    else
        printf("La letra 'A' si esta en la frase\n");

    return 0;
}

void ordInsercion(char array[], int n)
{
    int i,j;
    char aux;
    for(i = 1; i < n; i++){
        j = i;
        aux = array[i];
        while(i > 0 && aux < array[j - 1]){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
}

int busquedaBinaria(char array[], int n, char clave)
{
    int central,inicio,ultimo;
    int pivot;

    inicio = 0;
    ultimo = n-1;

    while(inicio <= ultimo){
        central = (inicio + ultimo)/2;
        pivot = array[central];

        if(clave == pivot)
            return central;
        else if(clave < pivot)
                ultimo = central - 1;
        else 
            inicio = central + 1;
    }
    return -1;
}
