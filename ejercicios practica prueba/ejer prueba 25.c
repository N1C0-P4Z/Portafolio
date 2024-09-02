#include <stdio.h>
#include <stdlib.h>

void cargarMatriz2(int m, int n, int (*p)[n]);
void ObtMatrizMaxima1(int *m, int *n, int (*p1)[*n], int (*p2)[*n], int (*p3)[*n]);
int main()
{   
    int m,n;

    printf("Ingrese el numero m: ");
    scanf("%d", &m);

    printf("Ingrese el numero n: ");
    scanf("%d", &n);

    int mat1[m][n];
    printf("Ingrese los datos de la matriz 1\n");
    cargarMatriz2(m,n,mat1);

    int mat2[m][n];
    printf("Ingrese los datos de la matriz 2\n");
    cargarMatriz2(m,n,mat2);

    int mat3[m][n];

    ObtMatrizMaxima1(&m,&n,mat1,mat2,mat3);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("[%d]", *(*(mat3 + i) + j));
        }
        printf("\n");
    }

    return 0;
}

void cargarMatriz2(int m, int n, int (*p)[n])
{   
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("Ingrese el numero de la posicion [%d][%d]: ",i,j);
            scanf("%d", *(p + i) + j);
        }
    }
}

void ObtMatrizMaxima1(int *m, int *n, int (*p1)[*n], int (*p2)[*n], int (*p3)[*n])
{   
    int n1, n2;
    for(int i=0; i<*m; i++){
        for(int j=0; j<*n; j++){
            n1 = *(*(p1 + i) + j);
            n2 = *(*(p2 + i) + j);

            if(n1 > n2){
                *(*(p3 + i) + j) = n1;
            }else{
                *(*(p3 + i) + j) = n2;
            }
        }
    }
}
