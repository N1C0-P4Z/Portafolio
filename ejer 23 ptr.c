#include <stdio.h>
#include <stdlib.h>

void cargarDatos(int *p, int n);
void intercambiarNumeros(int *p, int *q, int n, int m);

int main()
{   
    int n,m;

    printf("Ingrese el numero n: ");
    scanf("%d",&n);
    
    int array1[n];
    cargarDatos(array1,n);

    printf("Ingrese el numero m: ");
    scanf("%d", &m);

    int array2[m];
    cargarDatos(array2,m);

    intercambiarNumeros(array1, array2, n, m);

    for(int i=0; i<n; i++){
        printf("%d\n", *(array1 + i));
    }
    printf("\n");

    for(int i=0; i<m; i++){
        printf("%d\n", *(array2 + i));
    }

    return  0;
}

void cargarDatos(int *p, int n)
{   
    for(int i=0; i<n; i++){
        printf("Ingrese el numero %d: ",i);
        scanf("%d", p+i);
    }
}

void intercambiarNumeros(int *p, int *q, int n, int m)
{   
    int aux;
    int menor = n < m ? n : m;
    for(int i=0; i< menor; i++){
        aux = *(p + i);
        *(p + i) = *(q + i);
        *(q + i) = aux;
    }
}
