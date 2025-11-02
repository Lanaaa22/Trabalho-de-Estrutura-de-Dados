#include "tad_bdtimes.h"
#include "tad_time.c"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TIMES 45 // 10 times, turno único: (10 * 9) / 2 = 45 jogos

struct bdpartida {
    Time p[MAX_TIMES];
    int qtd;
};

