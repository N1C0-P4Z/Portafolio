#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordBurbuja(char [][100], int n);

int main()
{   
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    char array[n][100];
    for(int i = 0; i<n; i++){
        printf("Ingrese el nombre %d: ",i);
        scanf("%s", array[i]);
    }

    ordBurbuja(array,n);

    printf("La lista ordenada es\n");
    for(int i=0; i<n;i++){
        printf("%s ", array[i]);
    }
    printf("\n");

    return 0;
}

void ordBurbuja(char array[][100], int n)
{
    int i,j;
    int indiceIntercambio;
    char aux[100];
    i = n-1;

    while(i > 0)
    {
        indiceIntercambio = 0;
        for(j = 0; j < i; j++)
            if(strcmp(array[j + 1], array[j]) <0)
            {
                strcpy(aux, array[j]);
                strcpy(array[j], array[j + 1]);
                strcpy(array[j + 1], aux);
                indiceIntercambio = j;
            }
        i = indiceIntercambio;
    }
}
