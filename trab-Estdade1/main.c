#include <stdio.h>
#include "TADs/tad_time.h"
#include "TADs/tad_partida.h"
#include "TADs/system.h"

int main() {
    //lobby();
    //FUNÇÕES PARA TIME
    /*
    //cria o bdTime
    bdTimes *bdtime = createBDTimes();
    //Carrega os times no arquivo e insere em bdtime
    extraiArquivoTimes(bdtime);
    //imprime bdtime
    printBDTimes(bdtime);
    //desaloca memória de bdtime
    liberaBDTimes(bdtime);
    */
    //FUNÇÕES PARA PARTIDA
    bdPartidas *bdpartida = createBDPartidas();

    extraiArquivoPartidas(bdpartida);

    printBDPartidas(bdpartida);

    liberaBDPartidas(bdpartida);


    return 0;
}