#include <stdio.h>
#include "ex_3.h"

int num_par()
{
    int i,num,positivo = 0,negativo = 0,impar = 0,par = 0;
    printf("Entre com 10 números inteiros positivos:\n");
    for(i=0;i<10;i++){
        scanf("%d",&num);
        if(num % 2 == 0){
            par++;
        } if(num % 2 != 0){
            impar++;
        } if(num < 0){
            negativo++;
        } if(num > 0){
            positivo++;
        }
    }
    printf("Dos 10, %d número(s) é(são) par(es), %d número(s) é(são) impar(es), %d número(s) é(são) positivo(s) e %d número(s) é(são) negativo(s)\n",
           par, impar, positivo, negativo);

    return 0;
}