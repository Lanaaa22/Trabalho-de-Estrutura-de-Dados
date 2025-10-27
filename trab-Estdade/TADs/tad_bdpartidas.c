#include "tad_bdpartidas.h"
#include "tad_partida.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTIDAS 45 // 10 times, turno único: (10 * 9) / 2 = 45 jogos

struct bdpartida {
    Partida p[MAX_PARTIDAS];
    int qtd;
};

//Corrigir