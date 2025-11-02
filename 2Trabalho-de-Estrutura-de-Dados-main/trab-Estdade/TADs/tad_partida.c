#include "tad_partida.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct partida {
    int ID;          //Identificador da partida
    int Time1id;     //ID do primeiro time
    int Time2id;     //ID do segundo time
    int GolsTime1;   //Gols marcados pelo primeiro time
    int GolsTime2;   //Gols marcados pelo segundo time
};
