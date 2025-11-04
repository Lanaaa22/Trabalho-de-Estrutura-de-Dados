#include "consultar_partida.h"
#include "system.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void ConsultarPartida(bdTimes *bdt, bdPartidas *bdp) {
    printf("Escolha o modo de consulta:\n");
    printf("1 - Por time mandante\n");
    printf("2 - Por time visitante\n");
    printf("3 - Por time mandante ou visitante\n");
    printf("4 - Retornar ao menu principal\n");
    int option;
    scanf("%d", &option); // lê a opção digitada pelo usuário

    if (option == 1) {
        timeMandante(bdt, bdp);
    }
    else if (option == 2) {
        timeVisitante(bdt, bdp);
    } 
    else if (option == 3) {
        timeMandanteVisitante(bdt, bdp);
    }
    else if (option == 4) {
        lobby(bdt,bdp);
    }
}

char *nome(int id, bdTimes *bdt) {
    for (int i = 0; i < getQtdTimes(bdt); i++) {
        if (id == getIDTime(bdt, i)) {
            return getNomeTime(bdt, i);
        }
    }
    return NULL;
}
void timeMandante(bdTimes *bdt, bdPartidas *bdp) {
    printf("Digite o nome: ");
    char busca[50];
    while (getchar() != '\n');
    scanf("%[^\n]", busca);
    printf("%-4s %-10s %-7s %-10s\n", "ID", "Time 1", "","Time 2");
    for (int i = 0; i < getQtdPartidas(bdp); i++) {
        int time1ID = getTime1ID(bdp, i); // Pega o ID do time mandante
        char time1[100]; // Pega o nome do Time mandante através do ID
        strcpy(time1, nome(time1ID, bdt));
        if (strncmp(time1, busca, strlen(busca)) == 0)  { // Compara o nome com a busca
            int time2ID = getTime2ID(bdp, i);
            char time2[100];
            strcpy(time2, nome(time2ID, bdt));
            int GolsTime1 = getGolsTime1(bdp,i);
            int GolsTime2 = getGolsTime2(bdp,i);
            int IDPartida = getPartidaID(bdp,i);
            printf("%-4d %-10s %-2d x %-2d %-10s\n", IDPartida, time1, GolsTime1, GolsTime2, time2);

        }
    }
}

void timeVisitante(bdTimes *bdt, bdPartidas *bdp) {
   printf("Digite o nome: ");
    char busca[50];
    while (getchar() != '\n');
    scanf("%[^\n]", busca);
    printf("%-4s %-10s %-7s %-10s\n", "ID", "Time 1", "","Time 2");
    for (int i = 0; i < getQtdPartidas(bdp); i++) {
        int time2ID = getTime2ID(bdp, i); // Pega o ID do time mandante
        char time2[100]; // Pega o nome do Time mandante através do ID
        strcpy(time2, nome(time2ID, bdt));
        if (strncmp(time2, busca, strlen(busca)) == 0)  { // Compara o nome com a busca
            int time1ID = getTime1ID(bdp, i);
            char time1[100];
            strcpy(time1, nome(time1ID, bdt));
            int GolsTime1 = getGolsTime1(bdp,i);
            int GolsTime2 = getGolsTime2(bdp,i);
            int IDPartida = getPartidaID(bdp,i);
            printf("%-4d %-10s %-2d x %-2d %-10s\n", IDPartida, time1, GolsTime1, GolsTime2, time2);

        }
    }
}

void timeMandanteVisitante(bdTimes *bdt, bdPartidas *bdp) {
    printf("Digite o nome: ");
    char busca[50];
    while (getchar() != '\n');
    scanf("%[^\n]", busca);
    printf("%-4s %-10s %-7s %-10s\n", "ID", "Time 1", "","Time 2");
    for (int i = 0; i < getQtdPartidas(bdp); i++) {
        int time1ID = getTime1ID(bdp, i); // Pega o ID do time mandante
        char time1[100]; // Pega o nome do Time mandante através do ID
        strcpy(time1, nome(time1ID, bdt));
        int time2ID = getTime2ID(bdp, i);
        char time2[100];
        strcpy(time2, nome(time2ID, bdt));
        if (strncmp(time1, busca, strlen(busca)) == 0 || (strncmp(time2, busca, strlen(busca)) == 0))   { // Compara o nome com a busca   
            int GolsTime1 = getGolsTime1(bdp,i);
            int GolsTime2 = getGolsTime2(bdp,i);
            int IDPartida = getPartidaID(bdp,i);
            printf("%-4d %-10s %-2d x %-2d %-10s\n", IDPartida, time1, GolsTime1, GolsTime2, time2);

        }
    }
}