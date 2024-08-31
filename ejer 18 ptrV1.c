#include <stdio.h>
#include <stdlib.h>

void strcat(char *s, char *t);

int main()
{
    char s[200], t[200];

    printf("Ingrese la primer frase: ");
    scanf("%s", s);
    getchar();

    printf("Ingrese la segunda frase: ");
    scanf("%s", t);

    getchar();
    strcat(s,t);

    printf("%s\n",s);

    return 0;
}

void strcat(char *s, char *t)
{
    char *p, *q;

    for(q = *s; *s != '\0';q++);
    for(p = *t; *t != '\0'; p++, q++){
        *q = *p;
    }
    *q = '\0';
}
