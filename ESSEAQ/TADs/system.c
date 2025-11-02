#include "system.h"
#include "tad_time.h"
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

void Percorre_Times(char *buscar,bdTimes *bd) {
    for (int i = 0; i < bd->qtd; i++); { //percorre os times 
        for (int j = 0; j < strlen(buscar); j++) { // Percorre letras da busca 
                if (buscar[j] == bd->t[i]->nome[j]) { 
                    
                } // Compara Letra da busca com letra do time 
                } 
            } 
}
    

void ConsultaTime(bdTimes *bd) {
    LimpaTela();
    char busca[25];
    scanf("[^24\n]",busca);
    for (int i=0; i<bd->qtd; i++) {
        for (int j=0; strlen(busca); j++ ) {
            if (busca[j] == bd->t[i]->nome[j]);
        }
    }
    

}