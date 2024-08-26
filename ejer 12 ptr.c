#include <stdio.h>
#include <stdlib.h>

int strlenn(char *ptr); 

int main()
{   
    char frase[200];

    printf("Ingrese una frase: ");
    scanf("%s", frase);
    getchar(); 
    
    int longi= strlenn(frase);
    printf("%d\n", longi);

    return 0; 
}

int strlenn(char *ptr)
{
    int contador;
    for(contador=0; *ptr !='\0'; ptr++){
        contador++;
    }
    return contador; 
} 