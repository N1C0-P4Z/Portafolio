#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int m, int n, int (*p)[n]);
void obtenerMatrizMaxima(int *m, int *n, int (*p1)[*n], int (*p2)[*n], int (*p3)[*n]);

int main()
{
    int m,n;

    printf("Ingrese el numero m: ");
    scanf("%d", &m);

    printf("Ingrese el numero n: ");
    scanf("%d", &n);

    int mat1[m][n];
    printf("Ingrese los datos de mat1\n");
    cargarMatriz(m,n,mat1);

    int mat2[m][n];
    printf("Ingrese los datos de mat2\n");
    cargarMatriz(m,n,mat2);

    int mat3[m][n];

    obtenerMatrizMaxima(&m,&n,mat1,mat2,mat3);

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("[%d]", *(*(mat3 + i)+ j));
        }
        printf("\n");
    }

    return 0;
}
void cargarMatriz(int m, int n, int (*p)[n])
{
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("Ingrese el numero [%d][%d]: ",i,j);
            scanf("%d", *(p+i) + j);
        }
    }
}

void obtenerMatrizMaxima(int *m, int *n, int (*p1)[*n], int (*p2)[*n], int (*p3)[*n])
{
    int num1;
    int num2;
    for(int i = 0; i< *m; i++){
        for(int j = 0; j< *n; j++){
            num1 = *(*(p1 + i)+ j);
            num2 = *(*(p2 + i)+ j);
            if(num1 > num2)
                *(*(p3 + i)+ j) = num1;
            else
                *(*(p3 + i)+ j) = num2;
        }
    }
}
