#include "system.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void lobby() {  

    LimpaTela();

    printf("Escolha 1 opcao:\n");
    printf("1: Consultar Time\n");
    printf("2: Consultar Partidas\n");
    printf("3: Imprimir Tabela de Classificação\n");
    int option;
    scanf("%d", &option); // lê a opção digitada pelo usuário

    if (option == 1) {
        LimpaTela();
        //ConsultaTime()
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
        lobby();
    }
}

void LimpaTela() {
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Linux e macOS
    #endif
}

void ConsultaTime() {
    LimpaTela();
    printf("Digite as letras iniciais do time que deseja consultar:\n");
    char buscar;
    scanf("&s",buscar);
    

}