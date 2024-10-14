#include <stdlib.h>
#include <stdio.h>

void ordInsercion(int array[], int n);
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
    
    ordInsercion(array,c);
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

void ordInsercion(int array[], int n)
{
    int i,j;
    int aux;

    for(i = 1; i < n-1; i++){
        j = i;
        aux = array[i];
        while(j > 0 && aux > array[j - 1]){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;
    }
}

void diagonal(int array[], int n, int matriz[][n])
{
    for(int i = 0; i < n; i++)
        matriz[i][i] = array[i];
}
