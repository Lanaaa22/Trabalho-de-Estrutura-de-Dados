#include "system.h"
#include "consultar_time.h"
#include "consultar_partida.h"
#include "imprimir_classificacao.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void lobby(bdTimes *bdt, bdPartidas *bdp) {  

    LimpaTela();

    printf("Escolha 1 opcao:\n");
    printf("1: Consultar Time\n");
    printf("2: Consultar Partidas\n");
    printf("3: Imprimir Tabela de Classificação\n");
    int option;
    scanf("%d", &option); // lê a opção digitada pelo usuário

    if (option == 1) {
        LimpaTela();
        ConsultarTime(bdt, bdp);

    } 
    else if (option == 2) {
        LimpaTela();
        ConsultarPartida(bdt, bdp);
    } 
    else if (option == 3) {
        LimpaTela();
        Classificacao(bdt, bdp);
    }
    else {
        LimpaTela();
        printf("DIGITE UMA OPCAO VALIDA\n");
        printf("\n");
        lobby(bdt, bdp);
    }
}

