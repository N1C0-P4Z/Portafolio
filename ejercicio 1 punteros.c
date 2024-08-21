#include <stdio.h>
#include <stdlib.h>

int main(){
    /*Si una variable tiene que almacenar la direccion de la direcci´on de un car´acter, ¿Qu´e tipo debe tener la
variable*/
    char n = 'c';
    char *ptr = &n;
    char **ptr2 = ptr;

    printf("%p\n", ptr2);
    printf("%p\n", ptr);
    printf("%p\n", &n);

    return 0;
}