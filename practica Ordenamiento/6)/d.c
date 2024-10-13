#include <stdio.h>
#include <stdlib.h>

void convertirMatriz(int array[], int f, int c, int matriz[][c]);
void ordQuicksort(int array[], int primero, int ultimo);

int main()
{
    int f,c;

    printf("Ingrese el numero de filas: ");
    scanf("%d", &f);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &c);

    int cantN = f * c;
    int array[cantN];

    for(int i = 0; i < cantN; i++){
        printf("Ingrese el numero %d: ",i);
        scanf("%d", &array[i]);
    }

    ordQuicksort(array, 0, cantN - 1);

    int matriz[f][c];
    convertirMatriz(array,f,c,matriz);

    printf("La matriz ordenada es:\n");
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
void ordQuicksort(int array[], int primero, int ultimo)
{
    int i,j,central;
    int aux, pivot;

    central = (primero + ultimo)/2;
    pivot = array[central];

    i = primero;
    j = ultimo;

    do{
        while(array[i] < pivot) i++;
        while(array[j] > pivot) j--;

        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);

    if(primero < j)
        ordQuicksort(array,primero,j);
    if(i < ultimo)
        ordQuicksort(array, i, ultimo);
}
void convertirMatriz(int array[], int f, int c, int matriz[][c])
{
    int indice = 0;
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            matriz[i][j] = array[indice];
            indice++;
        }
    }
}