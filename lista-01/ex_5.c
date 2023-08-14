#include <stdio.h>
#include "ex_5.h"

int vetor()
{
    int tamanho_vetor,vetor[100],matriz[10][10] = {0},faltante = 0;
    printf("Escolha o tamanho do vetor(Será o valor escolhido - 1): ");
    scanf("%d", &tamanho_vetor);
    printf("Escolha os valores de 1 até N com um número faltante no vetor: ");
    for (int i = 1; i < tamanho_vetor; i++) {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < tamanho_vetor - 1; i++) {
        if (vetor[i] + 1 != vetor[i + 1]) {
            faltante = vetor[i] + 1;

        }
    }
    printf("O número que está faltando é o %d\n", faltante);

    return 0;
}