#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int busquedaSecuencial(char array[][100], int n, char clave[]);

int main()
{   
    int n;
    printf("Ingrese el numero de nombres: ");
    scanf("%d", &n);

    char array[n][100];
    for(int i = 0; i < n; i++){
        printf("Ingrese el nombre %d: ",i);
        scanf("%s", array[i]);
    }
    
    int esta = busquedaSecuencial(array,n,"Hugo");

    if(esta == -1)
        printf("El nombre 'Hugo' no se encuentra en la lista");
    else
        printf("El nombre 'Hugo' esta en la lista");

    return 0;
}

int busquedaSecuencial(char array[][100], int n, char clave[])
{   
   for(int i = 0; i < n; i++){
    if(strcmp(clave, array[i]) == 0)
        return 1;
   }
   return -1;
}


