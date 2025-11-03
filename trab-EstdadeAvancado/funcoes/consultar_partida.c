#include "consultar_partida.h"
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
        //timeVisitante();
    } 
    else if (option == 3) {
        //timeMandanteVisitante();
    }
}

void timeMandante(bdTimes *bdt, bdPartidas *bdp) {
    int nome;
    printf("Digite o nome: ");
    char busca[50];
    while (getchar() != '\n');
    scanf("%[^\n]", busca);

}