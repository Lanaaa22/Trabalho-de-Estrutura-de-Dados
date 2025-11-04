#include "imprimir_classificacao.h"
#include "auxiliares.h"
#include "consultar_time.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Classificacao(bdTimes *bdt, bdPartidas *bdp) {
    for(int i = 0; i < getQtdTimes(bdt); i++) {
        //printf("TIME %d: %s\n", i+1, bd->t[i]->nome);
        int id = getIDTime(bdt, i);
        int v = vitorias(id, bdp, bdt);
        int e = empates(id, bdp, bdt);
        int d = derrotas(id, bdp, bdt);
        int gm = golsMarcados(id, bdp, bdt);
        int gs = golsSofridos(id, bdp, bdt);
        printf("%d %s %d %d %d %d %d %d %d\n", id, getNomeTime(bdt, i), v, e, d, gm, gs, gm-gs, 3*v + e);
    }
}