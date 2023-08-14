#include <stdio.h>
#include "ex_6.h"

int matriz_identidade()
{
    int i,j,matriz[10][10] = {0};
    for (int i = 0; i < 10; i++) {
        matriz[i][i] = 1;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}