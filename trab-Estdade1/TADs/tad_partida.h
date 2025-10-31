#ifndef TAD_PARTIDA_H
#define TAD_PARTIDA_H

//Definição do dado Partida para representar uma informação de partida
typedef struct partida Partida;

//Definição do dado bdPartida para representar uma informação de bdpartida
typedef struct bdpartida bdPartidas;

void extraiArquivoPartidas(bdPartidas *bd);

void inserirBDPartidas(Partida *novaPartida, bdPartidas *bdp);

bdPartidas *createBDPartidas();

void printBDPartidas(bdPartidas *bd);

void liberaBDPartidas(bdPartidas *bd);

#endif