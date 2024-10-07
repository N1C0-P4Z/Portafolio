#include <stdio.h>
#include <stdlib.h>

void ordBurbuja1(float *a,int n);

int main()
{   
    int n;
    printf("Ingrese un numero: ");
    scanf("%d",&n);

    long array[n];
    for(int i = 0; i < n; i++){
        printf("Ingrese el valor %d: ",i);
        scanf("%f", &array[i]);
    }

    ordBurbuja1(array,n);

    printf("La lista ordenada\n");
    for(int i=0; i<n;i++)
        printf("%.2f ", array[i]);
    printf("\n");

    return 0;
}

void ordBurbuja1(float *a, int n)
{
    int i,j;
    int indiceIntercambio;
    float aux;

    i=n-1;
    while(i>0)
    {
        indiceIntercambio=0;
        for(j = 0; j < i; j++)
            if(a[j + 1] < a[j]){
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
                indiceIntercambio = j;
            }
        i = indiceIntercambio;
    }
}

#include <stdio.h>
#include <stdlib.h>

void insersionShort(float *a, int n);

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

void insersionShort(float *a, int n){
    int i,j;
    float aux;
    for(i = 1; i < n; i++){
        j=i;
        aux = a[i];
        while(j > 0 && aux < a[j-1]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = aux;
    }
}