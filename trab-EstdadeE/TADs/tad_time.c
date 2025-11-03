#include "tad_time.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct time {
    int id; //id dos times
    char nome[50]; //nome do time
};

#define MAX_TIMES 45 // 10 times, turno único: (10 * 9) / 2 = 45 jogos

struct bdtimes {
    Time *t[MAX_TIMES];
    int qtd;
};

//Função que carrega arquivo time.csv
void extraiArquivoTimes(bdTimes *bdt) {
    FILE *file = fopen("arquivos/times.csv", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    Time *novoTime; 
    char linha[255];
    fgets(linha, sizeof(linha), file); //ler o indice (pula o índice)
    while (fgets(linha, sizeof(linha), file) != NULL) {
        novoTime = (Time *)malloc(sizeof(Time));
        if (novoTime == NULL) {
        printf("Erro ao alocar memória");
    }
        sscanf(linha, "%d ,%49[^\n]", &novoTime->id, novoTime->nome);
        inserirBDtimes(novoTime, bdt);
    }
    fclose(file);
}

//Função que insere um novo time (do arquivo times.csv) na struct bdtime
void inserirBDtimes(Time *novoTime, bdTimes *bdt) {
    bdt->t[bdt->qtd] = novoTime;
    bdt->qtd++;
}

bdTimes *createBDTimes() //Cria e aloca memória para o estrutura BDTime
{
   bdTimes *bd = (bdTimes *)malloc(sizeof(bdTimes)); 
    if (bd == NULL) {
        printf("Erro ao alocar memória");
    }
   bd->qtd = 0;                                         
   for (int i = 0; i<MAX_TIMES; i++) {
        bd->t[i] = NULL;   
   }                                  
   

   return bd; 
}

void printBDTimes(bdTimes *bd) {
    for (int i = 0; i < bd->qtd; i++) {
        printf("Time %d:\n", i + 1);
        printf("  ID: %d\n", bd->t[i]->id);
        printf("  Nome: %s\n", bd->t[i]->nome);
    }
}

void liberaBDTimes(bdTimes *bd) {
    for(int i=0; i<bd->qtd; i++) {
        free(bd->t[i]);
    }
    free(bd);
}

void ConsultaTime(bdTimes *bdt, bdPartidas *bdp) {
    printf("Digite o nome do time ou prefixo: ");
    char busca[50];
    int encontrado = 0;
    while (getchar() != '\n');
    scanf("%[^\n]", busca);
    for(int i = 0; i < bdt->qtd; i++) {
        //printf("TIME %d: %s\n", i+1, bd->t[i]->nome);
        if (strncmp(bdt->t[i]->nome, busca, strlen(busca)) == 0) {
            int v = vitorias(bdt->t[i]->id, bdp, bdt);
            int e = empates(bdt->t[i]->id, bdp, bdt);
            int d = derrotas(bdt->t[i]->id, bdp, bdt);
            int gm = golsMarcados(bdt->t[i]->id, bdp, bdt);
            int gs = golsSofridos(bdt->t[i]->id, bdp, bdt);
            printf("%d %s %s %s %s %s %s %s %s\n", bdt->t[i]->id, bdt->t[i]->nome, v, e, d, gm, gs, gm-gs,3*v + e);

            encontrado = 1;
            
        }
    }
    if (!encontrado) {
        printf("Nenhum time com o nome %s foi encontrado", busca);
    }
} 

int vitorias(int id, bdPartidas *bdp, bdTimes *bdt) {
    int cont = 0;
    
    for(int j = 0; j < bdp->qtd; j++) {
        int Time1ID = bdp->p[j]->Time1id;
        int Time2ID = bdp->p[j]->Time2id;
        int Gol1 = bdp->p[j]->GolsTime1;
        int Gol2 = bdp->p[j]->GolsTime2;
        
        // Verifica se o time com o ID passado é o time 1 e venceu
        if ((id == Time1ID) && (Gol1 > Gol2)) {
            cont++;
        }
        // Verifica se o time com o ID passado é o time 2 e venceu
        else if ((id == Time2ID) && (Gol2 > Gol1)) {
            cont++;
        }
    }
    
    return cont;
}

int empates(int id, bdPartidas *bdp, bdTimes *bdt) {
    int cont = 0;
    
    for(int j = 0; j < bdp->qtd; j++) {
        int Time1ID = bdp->p[j]->Time1id;
        int Time2ID = bdp->p[j]->Time2id;
        int Gol1 = bdp->p[j]->GolsTime1;
        int Gol2 = bdp->p[j]->GolsTime2;
        
        // Verifica se o time com o ID passado é o time 1 e venceu
        if ((id == Time1ID) && (Gol1 == Gol2)) {
            cont++;
        }
        // Verifica se o time com o ID passado é o time 2 e venceu
        else if ((id == Time2ID) && (Gol2 == Gol1)) {
            cont++;
        }
    }
    
    return cont;
}

int derrotas(int id, bdPartidas *bdp, bdTimes *bdt) {
    int cont = 0;
    
    for(int j = 0; j < bdp->qtd; j++) {
        int Time1ID = bdp->p[j]->Time1id;
        int Time2ID = bdp->p[j]->Time2id;
        int Gol1 = bdp->p[j]->GolsTime1;
        int Gol2 = bdp->p[j]->GolsTime2;
        
        // Verifica se o time com o ID passado é o time 1 e venceu
        if ((id == Time1ID) && (Gol1 < Gol2)) {
            cont++;
        }
        // Verifica se o time com o ID passado é o time 2 e venceu
        else if ((id == Time2ID) && (Gol2 < Gol1)) {
            cont++;
        }
    }
    
    return cont;
}

int golsMarcados(int id, bdPartidas *bdp, bdTimes *bdt) {
    int cont = 0;
    
    for(int j = 0; j < bdp->qtd; j++) {
        int Time1ID = bdp->p[j]->Time1id;
        int Time2ID = bdp->p[j]->Time2id;
        int Gol1 = bdp->p[j]->GolsTime1;
        int Gol2 = bdp->p[j]->GolsTime2;
        
        // Verifica se o time com o ID passado é o time 1 e venceu
        if (id == Time1ID) {
            cont = cont + Gol1;
        }
        // Verifica se o time com o ID passado é o time 2 e venceu
        else if (id == Time2ID) {
            cont = cont + Gol2;
        }
    }
    
    return cont;
}

int golsSofridos(int id, bdPartidas *bdp, bdTimes *bdt) {
    int cont = 0;
    
    for(int j = 0; j < bdp->qtd; j++) {
        int Time1ID = bdp->p[j]->Time1id;
        int Time2ID = bdp->p[j]->Time2id;
        int Gol1 = bdp->p[j]->GolsTime1;
        int Gol2 = bdp->p[j]->GolsTime2;
        
        // Verifica se o time com o ID passado é o time 1 e venceu
        if (id == Time1ID) {
            cont = cont + Gol2;
        }
        // Verifica se o time com o ID passado é o time 2 e venceu
        else if (id == Time2ID) {
            cont = cont + Gol1;
        }
    }
    
    return cont;
}


