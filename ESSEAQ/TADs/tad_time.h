#ifndef TAD_TIME_H
#define TAD_TIME_H

//Definição do dado Time para representar uma informação de time
typedef struct time Time;

//Definição do tipo de dados bdTime para representar uma informação de bdtime
typedef struct bdtimes bdTimes;

//Definição de função que carrega o arquivo times.csv
void extraiArquivoTimes(bdTimes *bdt);

//Definição de função que insere a struct novoTime em bdtime
void inserirBDtimes(Time *novoTime, bdTimes *bdt);

//Definição de função que cria um novo bdtime
bdTimes *createBDTime();

//Definição de função que imprime um bdtime
void printBDTimes(bdTimes *bd);

//Definição de função que libera bdtime
void liberaBDTimes(bdTimes *bd);

#endif