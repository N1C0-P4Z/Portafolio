#include <stdio.h>
#include <stdlib.h>

void cargarMatriz1(int m, int n, int (*p)[n]);

void intercambiarNros1(int m, int n, int (*p1)[n], int (*p2)[n]);

int main()
{   
    int m,n;

    printf("Ingrese el numero m: ");
    scanf("%d", &m);

    printf("Ingrese el numero n: ");
    scanf("%d", &n);

    int array1[m][n];
    printf("Ingrese los elemntos de la matriz 1\n");
    cargarMatriz1(m,n,array1);

    int array2[m][n];
    printf("Ingrese los elementos de la matriz 2\n");
    cargarMatriz1(m,n,array2);

    intercambiarNros1(m,n,array1,array2);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("[%d]", *(*(array1 + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("[%d]", *(*(array2 + i) + j));
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%p  %p\n", &array1[i][j], &array2[i][j]);
        }
    }
    return 0;
}


void cargarMatriz1(int m, int n, int (*p)[n])
{
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("Ingrese el numero de la posicion [%d][%d]: ",i,j);
            scanf("%d", *(p + i) + j);
        }
    }
}

void intercambiarNros1(int m, int n, int (*p1)[n], int (*p2)[n])
{
    int aux;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            aux= *(*(p1 + i) + j);
            *(*(p1 + i)+ j) = *(*(p2 + i) + j);
            *(*(p2 + i)+ j) = aux;
        }
    }
}
