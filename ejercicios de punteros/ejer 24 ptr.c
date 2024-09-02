#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int m, int n, int (*p)[n]);
void intercambiarNumeros(int m, int n, int (*p1)[n], int (*p2)[n]);

int main()
{
    int m,n;

    printf("Ingrese el numero m: ");
    scanf("%d", &m);

    printf("Ingrese el numero n: ");
    scanf("%d", &n);

    int array1[m][n];
    printf("Ingrese los datos del array1\n");

    cargarMatriz(m,n,array1);

    int array2[m][n];
    printf("Ingrese los datos del array2\n");

    cargarMatriz(m,n,array2);

    intercambiarNumeros(m,n,array1,array2);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("[%d]", *(*(array1 + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("[%d]", *(*(array2 + i) + j));
        }
        printf("\n");
    }

    return 0;
}

void cargarMatriz(int m, int n, int (*p)[n])
{
    for(int i=0; i < m ; i++){
        for(int j=0; j < n; j++){
            printf("Ingrese el numero [%d][%d]: ", i,j);
            scanf("%d", *(p + i) + j);
        }
    }
}

void intercambiarNumeros(int m, int n, int (*p1)[n], int (*p2)[n])
{
    int aux;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            aux  = *(*(p1 + i) + j);
            *(*(p1 + i) + j) = *(*(p2 + i) + j);
            *(*(p2 + i) + j) = aux;
        }
    }
}
