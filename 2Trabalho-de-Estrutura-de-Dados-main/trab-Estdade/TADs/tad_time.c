#include "tad_time.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../extrairArq.h"

struct time {
    int id; //id dos times
    char nome[50]; //nome do time
};




/*
void extraiArquivoTime() {
    FILE *file = fopen("arquivos/times.csv", "r");
    char ch; 
    //int qtd = contatimes(l); //fazer depois uma função que conte a quantidade de times no CSV
    //Time *times = (Time *)malloc(sizeof(Time) * qtd);
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    fclose(file);
}
*/