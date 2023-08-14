#include <stdio.h>
#include <string.h>
#include"ex_7.h"

int palindromo()
{
    int i,j;
    char palavra[100],inverso[100];
    printf("Digite a palavra ou frase:");
    scanf("%s",palavra);
    j = 1;
    for(i = 0; i < strlen(palavra);i++){
        inverso[i] = palavra[strlen(palavra) - j];
        j++;
    }
    if(strcmp(palavra,inverso) == 0){
        printf("'%s' é uma palavra palindroma.\n", palavra);
    } else{
        printf("'%s' não é uma palavra palindroma.\n",palavra);
    }
    return 0;
}