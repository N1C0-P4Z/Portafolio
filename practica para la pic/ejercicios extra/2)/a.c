#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nombreJuego[30];
    char nombreEmpresa[30];
    int minutosJugados;
    int nivelDelPersonaje;
    char resultado[30];
}partida;

void getPartida(int n, int m, partida array[n][m]);
void contPartidasLol(int n, int m, partida array[n][m]);
void partidaMayorNivel(int n, int m, partida array[n][m]);
void almacenarPartidasGanadas(int n, int m, partida array[n][m], int dia, partida ganadasDia[m]);
int compararPartidas(partida a, partida b);
void ordInsercion(int m, int n, partida array[n][m]);
void ordInsercionDia(int m, partida ganadaDia[m]);

int main()
{
    int n,m;
    printf("Ingrese la cantidad de partidas jugadas: ");
    scanf("%d", &n);
    printf("Ingrese la cantidad de dias jugados: ");
    scanf("%d", &m);

    partida array[n][m];

    getPartida(n,m,array);

    //1 hecho
    contPartidasLol(n,m,array);
    //2 hecho
    partidaMayorNivel(n,m,array);

    partida ganadasDia[m];

    int diaespecifico;
    printf("Ingrese el dia en especifico: ");
    scanf("%d", &diaespecifico);
    almacenarPartidasGanadas(n,m,array,diaespecifico, ganadasDia);

    printf("Las partidas ganas del día: %d\n",diaespecifico);
    for(int i = 0; i< m; i++){
        printf("Juego: %s\n", ganadasDia[i].nombreJuego);
        printf("Empresa: %s\n", ganadasDia[i].nombreEmpresa);
        printf("Minutos Jugados: %d\n", ganadasDia[i].minutosJugados);
        printf("Nivel del personaje obtenido: %d\n", ganadasDia[i].nivelDelPersonaje);
        printf("\n");
    }
    //3 hecho

    ordInsercion(n,m,array);
    printf("Las partidas ordenadas son:\n");
    for(int i = 0; i < n;i++){
        printf("Juego: %s\n", array[i]->nombreJuego);
        printf("Empresa: %s\n", array[i]->nombreEmpresa);
        printf("Minutos Jugados: %d\n", array[i]->minutosJugados);
        printf("Nivel del personaje obtenido: %d\n", array[i]->nivelDelPersonaje);
        printf("Resultado: %s\n", array[i]->resultado);
        printf("\n");
    }

    ordInsercionDia(m,ganadasDia);
    printf("Las partidas ganadas en el dia en especifio son:\n");
    for(int i = 0; i < n; i++){
        printf("Juego: %s\n", ganadasDia[i].nombreJuego);
        printf("Empresa: %s\n", ganadasDia[i].nombreEmpresa);
        printf("Minutos Jugados: %d\n", ganadasDia[i].minutosJugados);
        printf("Nivel del personaje obtenido: %d\n", ganadasDia[i].nivelDelPersonaje);
        printf("\n");
    }

    return 0;
}

void getPartida(int n, int m, partida array[n][m])
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        getchar();
        printf("Ingrese el nombre del juego [%d][%d]: ",i,j);
        scanf("%s", array[i][j].nombreJuego);
        getchar();
        printf("Ingrese el nombre de la empresa [%d][%d]: ",i,j);
        scanf("%s", array[i][j].nombreEmpresa);
        printf("Ingrese la cantidad de minutos juegados [%d][%d]: ",i,j);
        scanf("%d", &array[i][j].minutosJugados);
        printf("Ingrese el nivel del personaje[%d][%d]: ",i,j);
        scanf("%d", &array[i][j].nivelDelPersonaje);
        getchar();
        printf("Ingrese el resultado[%d][%d]: ",i,j);
        scanf("%s", array[i][j].resultado);
        printf("\n");
        }
    }
}

void contPartidasLol(int n, int m, partida array[n][m])
{   
    int partidasPrimerDia = 0, partidasUltimoDia = 0;

    for(int i = 0; i < m; i++){
        if(strcmp(array[0][i].nombreJuego, "LOL")==0)
            partidasPrimerDia++;
    }
    for(int i = 0; i < n; i++){
        if(strcmp(array[n-1][i].nombreJuego, "LOL")==0)
            partidasUltimoDia++;
    }

    printf("Las partidas jugadas de LOL en el primer dia fueron:%d\n", partidasPrimerDia);
    printf("Las partidas jugadas de LOL en el ultimo dia fueron:%d\n", partidasUltimoDia);

    if(partidasUltimoDia >= partidasPrimerDia)
        printf("Mucho Vicio. Poco Estudio\n");
}

void partidaMayorNivel(int n, int m, partida array[n][m])
{
    for(int i = 0; i < m; i++){
        int nivelMax = 0;
        int indiceMax = 0;

        for(int j = 0; j < n; j++){
            if(array[i][j].nivelDelPersonaje > nivelMax){
                nivelMax = array[i][j].nivelDelPersonaje;
                indiceMax = j;
            }
        }

        if(indiceMax != 0){
            printf("Dia:%d\n",i);
            printf("Mayor Nivel Obtenido:%d\n",nivelMax);
            if(strcmp(array[i][indiceMax].resultado, "Gano")==0){
                printf("Gano\n");
            }
            else
                printf("Perdio\n");
        }
    }
}

void almacenarPartidasGanadas(int n, int m, partida array[n][m], int dia, partida ganadasDia[m])
{
    int aux=0;

    for(int i = 0; i < m; i++){
        if(strcmp(array[dia][i].resultado, "Gano")==0){
            ganadasDia[aux++] = array[dia][i];
        }
    }
}

int compararPartidas(partida a, partida b)
{   
    if(a.nivelDelPersonaje == b.nivelDelPersonaje){
        if(a.minutosJugados > b.minutosJugados)
            return -1;
        else if(a.minutosJugados < b.minutosJugados)
            return 1;
    }else{
        if(a.nivelDelPersonaje > b.nivelDelPersonaje)
            return -1;
        else if(a.nivelDelPersonaje < b.nivelDelPersonaje)
            return 1;
    }
    return 0;
}

void ordInsercionDia(int m, partida ganadasDia[m])
{
    int i,j;
    partida aux;
    for(j = 1; j < m; j++){
        i = j;
        aux= ganadasDia[i];
        while(j > 0 && compararPartidas(aux, ganadasDia[j - 1])>0){
            ganadasDia[j] = ganadasDia[j - 1];
            j--;
        }
        ganadasDia[j] = aux;
    }
}

void ordInsercion(int n, int m, partida array[n][m])
{
    int i,j;
    partida aux;

    for(i = 0; i < n; i++){
        for(j = 1; j < m; j++){
            int k = j;
            aux = array[i][j];
            while(k > 0 && compararPartidas(aux, array[i][k - 1])<0){
                array[i][k] = array[i][k - 1];
                k--;
            }
a            array[i][k] = aux;
        }
    }
}
