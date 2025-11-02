#include "system.h"
#include "tad_time.h"
#include "tad_partida.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void lobby(bdTimes *bd) {  

    printf("Escolha 1 opcao:\n");
    printf("1: Consultar Time\n");
    printf("2: Consultar Partidas\n");
    printf("3: Imprimir Tabela de Classificação\n");
    int option;
    scanf("%d", &option); // lê a opção digitada pelo usuário

    if (option == 1) {
        LimpaTela();
        printf("DIGITE PREFIXO: \n");
        ConsultaTime(bd);
        printf("\n");
        printf("\n");
        lobby(bd);
    } 
    else if (option == 2) {
        LimpaTela();
        //ConsultaPartida()
        printf("\n");
        printf("\n");
        lobby(bd);
    } 
    else if (option == 3) {
        LimpaTela();
        //Classificacao()
        printf("\n");
        printf("\n");
        lobby(bd);
    }
    else {
        LimpaTela();
        printf("DIGITE UMA OPCAO VALIDA\n");
        printf("\n");
        printf("\n");
        lobby(bd);
    }
}

void LimpaTela() {
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Linux e macOS
    #endif
}

