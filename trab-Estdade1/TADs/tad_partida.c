#include "tad_partida.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct partida {
    int id;          //Identificador da partida
    int Time1id;     //ID do primeiro time
    int Time2id;     //ID do segundo time
    int GolsTime1;   //Gols marcados pelo primeiro time
    int GolsTime2;   //Gols marcados pelo segundo time
};

#define MAX_PARTIDAS 90 // 10 times, turno único: (10 * 9) / 2 = 45 jogos

struct bdpartida {
    Partida *p[MAX_PARTIDAS];
    int qtd;
};

//Função que carrega arquivo partidas
void extraiArquivoPartidas(bdPartidas *bdp) {
    FILE *file = fopen("arquivos/partidas_completo.csv", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    Partida *novaPartida;
    char linha[255];
    fgets(linha, sizeof(linha), file); //ler o indice (pula o índice)
    while (fgets(linha, sizeof(linha), file) != NULL) {
        novaPartida = (Partida *)malloc(sizeof(Partida));
        if (novaPartida == NULL) {
            printf("Erro ao alocar memória");
        }
        sscanf(linha, "%d %d %d %d %d", &novaPartida->id, &novaPartida->Time1id, &novaPartida->Time2id, &novaPartida->GolsTime1, &novaPartida->GolsTime2);
        inserirBDPartidas(novaPartida, bdp);
    }
    fclose(file);
}

void inserirBDPartidas(Partida *novaPartida, bdPartidas *bdp) {
    if (bdp->qtd >= MAX_PARTIDAS) {
        printf("Erro ao inserir mais partidas");
        return;
    } else {
        bdp->p[bdp->qtd] = novaPartida;
        bdp->qtd++;
    }

}

bdPartidas *createBDPartidas() {
    bdPartidas *bd = (bdPartidas *)malloc(sizeof(bdPartidas));
    if (bd == NULL) {
        printf("Erro ao alocar memória");
    }
    bd->qtd = 0;
       for (int i = 0; i<MAX_PARTIDAS; i++) {
        bd->p[i] = NULL;   
    }
    return bd;
}

void printBDPartidas(bdPartidas *bd) {
    for (int i = 0; i < bd->qtd; i++) {
        printf("Partida %d:\n", i + 1);
        printf("  ID: %d\n", bd->p[i]->id);
        printf("  ID do time 1: %d\n", bd->p[i]->Time1id);
        printf("  ID do time 2: %d\n", bd->p[i]->Time2id);
        printf("  Gols do time 1: %d\n", bd->p[i]->GolsTime1);
        printf("  Gols do time 2: %d\n", bd->p[i]->GolsTime2);
    }

}

void liberaBDPartidas(bdPartidas *bd) {
    for(int i=0; i<bd->qtd; i++) {
        free(bd->p[i]);
    }
    free(bd);
}