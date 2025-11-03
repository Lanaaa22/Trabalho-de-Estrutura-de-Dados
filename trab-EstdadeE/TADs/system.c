#include "system.h"
#include "tad_partida.h"
#include "tad_time.h"
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
        ConsultaTime(bdt, bdp);
    } 
    else if (option == 2) {
        LimpaTela();
        //ConsultaPartida()
    } 
    else if (option == 3) {
        LimpaTela();
        //Classificacao()
    }
    else {
        LimpaTela();
        printf("DIGITE UMA OPCAO VALIDA\n");
        printf("\n");
        lobby(bdt, bdp);
    }
}

void LimpaTela() {
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Linux e macOS
    #endif
}

