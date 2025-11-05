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
        ConsultarPartida(bdt, bdp);
    }
    else if (option == 2) {
        timeVisitante(bdt, bdp);
        ConsultarPartida(bdt, bdp);
    } 
    else if (option == 3) {
        timeMandanteVisitante(bdt, bdp);
        ConsultarPartida(bdt, bdp);
    }
    else if (option == 4) {
        LimpaTela();
        lobby(bdt,bdp);
    }
    else {
        LimpaTela();
        printf("---------------------\n\n");
        printf("ERRO - Digite uma opção válida\n");
        printf("---------------------\n\n");
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
    LimpaTela();
    printf("Digite o nome do time mandante: ");
    char busca[50];
    while (getchar() != '\n');
    scanf("%[^\n]", busca);
    int cont = 0;
    for (int i = 0; i < getQtdPartidas(bdp); i++) {
        int time1ID = getTime1ID(bdp, i); // Pega o ID do time mandante
        char time1[100]; // Pega o nome do Time mandante através do ID
        strcpy(time1, nome(time1ID, bdt));
        if (strncmp(time1, busca, strlen(busca)) == 0)  { // Compara o nome com a busca
            cont = cont + 1;
            if (cont == 1) { // Printa os indices apenas se for a primeira vez
                printf("%-4s %-10s %-7s %-10s\n", "ID", "Time 1", "","Time 2");
            }
            int time2ID = getTime2ID(bdp, i);
            char time2[100];
            strcpy(time2, nome(time2ID, bdt));
            int GolsTime1 = getGolsTime1(bdp,i);
            int GolsTime2 = getGolsTime2(bdp,i);
            int IDPartida = getPartidaID(bdp,i);
            printf("%-4d %-10s %-2d x %-2d %-10s\n", IDPartida, time1, GolsTime1, GolsTime2, time2);
        }
    }
    if (cont == 0) {
        LimpaTela();
        printf("---------------------\n\n");
        printf("Sem registros de partidas como mandante do time %s\n\n", busca);
        printf("---------------------\n\n");
    }
}

void timeVisitante(bdTimes *bdt, bdPartidas *bdp) {
    LimpaTela();
    printf("Digite o nome do time visitante: ");
    char busca[50];
    while (getchar() != '\n');
    scanf("%[^\n]", busca);
    printf("%-4s %-10s %-7s %-10s\n", "ID", "Time 1", "","Time 2");
    int cont = 0;
    for (int i = 0; i < getQtdPartidas(bdp); i++) {
        int time2ID = getTime2ID(bdp, i); // Pega o ID do time mandante
        char time2[100]; // Pega o nome do Time mandante através do ID
        strcpy(time2, nome(time2ID, bdt));
        if (strncmp(time2, busca, strlen(busca)) == 0)  { // Compara o nome com a busca
            cont = cont + 1;
            if (cont == 1) { // Printa os indices apenas se for a primeira vez
                printf("%-4s %-10s %-7s %-10s\n", "ID", "Time 1", "","Time 2");
            }
            int time1ID = getTime1ID(bdp, i);
            char time1[100];
            strcpy(time1, nome(time1ID, bdt));
            int GolsTime1 = getGolsTime1(bdp,i);
            int GolsTime2 = getGolsTime2(bdp,i);
            int IDPartida = getPartidaID(bdp,i);
            printf("%-4d %-10s %-2d x %-2d %-10s\n", IDPartida, time1, GolsTime1, GolsTime2, time2);
        }
    }
    if (cont == 0) {
        LimpaTela();
        printf("---------------------\n\n");
        printf("Sem registros de partidas como visitante do time %s\n\n", busca);
        printf("---------------------\n\n");
    }
}

void timeMandanteVisitante(bdTimes *bdt, bdPartidas *bdp) {
    LimpaTela();
    printf("Digite o nome do time mandante ou visitante: ");
    char busca[50];
    while (getchar() != '\n');
    scanf("%[^\n]", busca);
    int cont = 0;
    for (int i = 0; i < getQtdPartidas(bdp); i++) {
        int time1ID = getTime1ID(bdp, i); // Pega o ID do time mandante
        char time1[100]; // Pega o nome do Time mandante através do ID
        strcpy(time1, nome(time1ID, bdt));
        int time2ID = getTime2ID(bdp, i);
        char time2[100];
        strcpy(time2, nome(time2ID, bdt));
        if (strncmp(time1, busca, strlen(busca)) == 0 || (strncmp(time2, busca, strlen(busca)) == 0))   { // Compara o nome com a busca   
            cont = cont + 1;
            if (cont == 1) { // Printa os indices apenas se for a primeira vez
                printf("%-4s %-10s %-7s %-10s\n", "ID", "Time 1", "","Time 2");
            }
            int GolsTime1 = getGolsTime1(bdp,i);
            int GolsTime2 = getGolsTime2(bdp,i);
            int IDPartida = getPartidaID(bdp,i);
            printf("%-4d %-10s %-2d x %-2d %-10s\n", IDPartida, time1, GolsTime1, GolsTime2, time2);
        }
    }
    if (cont == 0) {
        LimpaTela();
        printf("---------------------\n\n");
        printf("Sem registros de partidas como mandante ou visitante do time %s \n\n", busca);
        printf("---------------------\n\n");
    }
}   