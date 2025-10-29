#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void extraiArquivo(const char *nome) {
    char ch; 
    char caminho[100]; //vetor para armazenar o caminho da
    strcat(strcpy(caminho, "arquivos/"), nome);
    FILE *file = fopen(caminho, "r");
    //int qtd = contatimes(l); //fazer depois uma função que conte a quantidade de times no CSV
    //Time *times = (Time *)malloc(sizeof(Time) * qtd);
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
        //fazer os berecuteco top
    }
    fclose(file);
}