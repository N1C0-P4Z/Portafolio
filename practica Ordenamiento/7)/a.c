#include <stdlib.h>
#include <stdio.h>

void ordBurbuja(int array[], int n);
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
    
    ordBurbuja(array,c);
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

void diagonal(int array[], int n, int matriz[][n])
{
    for(int i = 0; i < n; i++)
        matriz[i][i] = array[i];
}
