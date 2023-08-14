#include <stdio.h>
#include "ex_1.h"

int maior_num()
{
    int maior = 0 , num = 1;
    printf("Entre com os números desejados: ");
    for (;num != 0;){
        scanf("%d",&num);
        if(num>maior){
            maior = num;
        }
    }
    printf("O maior número é o %d\n", maior);
    return 0;
}