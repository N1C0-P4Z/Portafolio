#include <stdio.h>
#include <stdlib.h>

void insersionShort(float array[], int n);

int main(){

    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    float array[n];
    for(int i= 0; i<n; i++){
        printf("Ingrese el valor %d: ",i);
        scanf("%f", &array[i]);
    }

    insersionShort(array,n);

    printf("La lista ordenada es:\n");
    for(int i = 0; i < n; i++)
        printf("%.2f ", array[i]);
    printf("\n");

    return 0;
}

void insersionShort(float array[], int n){
    int i,j;
    float aux;
    for(i = 1; i < n; i++){
        j=i;
        aux = array[i];
        while(j > 0 && aux < array[j-1]){
            array[j] = array[j-1];
            j--;
        }
        array[j] = aux;
    }
}