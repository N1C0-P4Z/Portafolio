#include <stdlib.h>
#include <stdio.h>

void ordQuicksort(int array[], int inicio, int ultimo);
void diagonal(int array[], int n, int matriz[][n]);

int main()
{   
    int c;
    printf("Ingrese la dimension de la matriz cuadrada: ");
    scanf("%d", &c);

    int matriz[c][c];
    int array[c];
    int n, aux = 0;

    for(int i = 0; i < c; i++)
        for(int j = 0; j < c; j++){
            printf("Ingrese el valor de la posicion [%d][%d]: ",i,j);
            scanf("%d", &n);
            if(i == j){
                array[aux] = n;
                aux++; 
            }else{
                matriz[i][j] = n;
            }
        }
    
    ordQuicksort(array,0,c-1);
    diagonal(array,c,matriz);

    printf("La matriz con diagonal ordenada es:\n");
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void ordQuicksort(int array[], int inicio, int ultimo)
{
    int i,j,central;
    int aux,pivot;

    central = (inicio + ultimo)/2;
    pivot = array[central];

    i = inicio;
    j = ultimo;

    do{
        while(array[i] > pivot) i++;
        while(array[j] < pivot) j--;

        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--; 
        }
    }while(i <= j);

    if(inicio < j)
        ordQuicksort(array,inicio,j);

    if(i < ultimo)
        ordQuicksort(array, i, ultimo);
}

void diagonal(int array[], int n, int matriz[][n])
{
    for(int i = 0; i < n; i++)
        matriz[i][i] = array[i];
}
