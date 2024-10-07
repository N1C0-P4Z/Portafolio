#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordSeleccion(char array[][100], int n);

int main()
{
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    char array[n][100];
    for(int i=0; i<n; i++){
        printf("Ingrese el nombre %d: ",i);
        scanf("%s", array[i]);
    }

    ordSeleccion(array,n);

    printf("La lista ordenada es\n");

    for(int i = 0; i < n; i++){
        printf("%s ", array[i]);
    }
    printf("\n");

    return 0;
}

void ordSeleccion(char array[][100], int n)
{   
    int indiceMenor,i,j;
    char aux[100];
    for(i = 0; i < n-1; i++)
    {
        indiceMenor = i;
        for(j = i+1; j < n; j++)
            if(strcmp(array[j], array[indiceMenor])<0)
               indiceMenor = j;
            if(i != indiceMenor)
            {
                strcpy(aux, array[i]);
                strcpy(array[i], array[indiceMenor]);
                strcpy(array[indiceMenor],aux);
            } 
    }
}
