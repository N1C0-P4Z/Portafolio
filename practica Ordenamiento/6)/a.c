#include <stdio.h>
#include <stdlib.h>

void convertirMatriz(int array[], int f, int c, int matriz[][c]);
void ordBurbuja(int array[], int n);

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

    ordBurbuja(array, cantN);

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


void ordBurbuja(int array[], int n)
{
    int i,j,indiceIntercambio;
    int aux;

    i = n-1;
    while(i > 0){
        indiceIntercambio = 0;
        for(j = 0; j < i; j++)
            if(array[j + 1] < array[j]){
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                indiceIntercambio = j;
            }
        i = indiceIntercambio;
    }
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