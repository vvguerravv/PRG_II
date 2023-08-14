#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ex_2.h"

int advinhador()
{
    int sorteado,num;
    sorteado = 1 + rand() %10;
    printf("Escolha um número de 1 a 10: ");
    scanf("%d",&num);
    if(sorteado == num){
        printf("Parabéns você acertou\n");
    } else{
        printf("Tente outra vez!\n");
    }
}