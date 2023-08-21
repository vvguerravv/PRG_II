#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "arquivo.h"

typedef struct{
    char conteudo[20];
    int total;
} palavra_t;

int ler_arquivo(char *nome[],char *palavra[])
{
    FILE *arquivo;

    arquivo = fopen(nome,"r");

    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

//    char linha [100];
//    int total_palavra=0;

    char linha[100];
    palavra_t todas[1000] = {};
    int total_todas = 0;


    while(fscanf(arquivo, "%s", linha)!= EOF){
        bool achou = false;
        for (int i = 0; i < total_todas; i++){
            if (strcmp(linha,todas[i].conteudo) == 0){
                todas[i].total++;
                achou = true;
                break;
            }
        }
        if (!achou){
            strcpy(todas[total_todas].conteudo,linha);
            todas[total_todas].total = 1;
            total_todas++;
        }

    }
    for(int i = 0;i < total_todas; i++){
        printf("A palavra %s apareceu %d vez(es)\n",todas[i].conteudo,todas[i].total);
    }



    // TODO imprimir vetores

    todas[0].total++;



    return 0;
}
