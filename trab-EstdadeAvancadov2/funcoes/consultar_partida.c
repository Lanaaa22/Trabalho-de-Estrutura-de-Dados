#include "consultar_partida.h"
#include "auxiliares.h"
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
        printf("OPCAO 1 ESCOLHIDA");
        timeMandante(bdt, bdp);
    }
    else if (option == 2) {
        //timeVisitante();
    } 
    else if (option == 3) {
        //timeMandanteVisitante();
    }
}

char *nome(int id, bdTimes *bdt) {
    for (int i = 0; i < getQtdTimes(bdt); i++) {
        if (id == getIDTime(bdt)) {
            return getNomeTime(bdt, i);
        }
    }
    return NULL;
}
void timeMandante(bdTimes *bdt, bdPartidas *bdp) {
    printf("Cheguei no time mandante");
    printf("Digite o nome: ");
    char busca[50];
    printf("Chegando no whileeee");
    while (getchar() != '\n');
    scanf("%[^\n]", busca);
    printf("aaaaaaa to fora do for ainda");
    for (int i = 0; i < getQtdPartidas(bdp); i++) {
        printf("relaxa, agora to no for");
        int time1ID = getTime1ID(bdp, i); // Pega o ID do time mandante
        char time1[100] = nome(time1ID, bdt); // Pega o nome do Time mandante através do ID
        printf("Ei, to fora do if ainda");
        if (strncmp(time1, busca, strlen(busca)) == 0)  { // Compara o nome com a busca
            printf("Opa, to no if");
            int time2ID = getTime2ID(bdp, i);
            char time2[100] = nome(time2ID, bdt);
            int GolsTime1 = getGolsTime1(bdp,i);
            int GolsTime2 = getGolsTime2(bdp,i);
            int IDPartida = getPartidaID(bdp,i);
            printf("%d, %s, %d, x %d, %s", IDPartida, time1, GolsTime1, GolsTime2, time2);

        }
        printf("TOP, SAI DO IF");
    }

}