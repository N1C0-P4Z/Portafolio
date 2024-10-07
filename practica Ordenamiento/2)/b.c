#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insersionShort(char array[][100], int n);

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

    insersionShort(array,n);

    printf("La lista ordenada es\n");

    for(int i = 0; i < n; i++){
        printf("%s ", array[i]);
    }
    printf("\n");

    return 0;
}

void insersionShort(char array[][100], int n)
{   
    int i,j;
    char aux[100];

    for(i = 1; i < n; i++)
    {
        j = i;
        strcpy(aux, array[i]);
        while(j > 0 && strcmp(aux, array[j - 1])< 0)
        {
            strcpy(array[j], array[j - 1]);
            j--;
        }
        strcpy(array[j],aux);
    }
}
