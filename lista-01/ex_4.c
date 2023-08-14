#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ex_4.h"

int jogo_azar()
{
    int sorteado,palpite_do_jogador,palpites_possiveis[100] = {0};
    sorteado = 1 + rand() %100;
    printf("Advinhe um número de 1 a 100\n");
    for(;palpite_do_jogador != sorteado;){
        printf("Escolha um número: ");
        scanf("%d",&palpite_do_jogador);

        if(palpite_do_jogador < 1 || palpite_do_jogador > 100){
            printf("Escolha um número de 1 a 100\n");
        }

        if(palpites_possiveis[palpite_do_jogador - 1] != 0){
            printf("Você já escolheu %d vez(es) o número %d. Escolha outra número.\n", palpites_possiveis[palpite_do_jogador - 1], palpite_do_jogador);
        }

        palpites_possiveis[palpite_do_jogador - 1]++;

        if(palpite_do_jogador == sorteado){
            printf("Parabéns, você acertou!\n");
        } else{
            printf("Tente novamente!\n");
        }
    }

    return 0;
}